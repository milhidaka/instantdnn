import { shuffle, permutation, normal_random } from "./util";
// logistic regression classifier
export class Classifier {
  lr: number = 0.01;
  decay: number = 0.001;
  epochs: number = 10;
  weight: Float32Array;// feature_dims * n_classes
  bias: Float32Array;//n_classes

  constructor(public feature_dims: number, public n_classes: number) {
    this.init_weight();
  }

  private init_weight() {
    this.weight = new Float32Array(this.feature_dims * this.n_classes);
    let sigma = Math.sqrt(2.0 / this.feature_dims);//He's init
    for (let i = 0; i < this.weight.length; i++) {
      this.weight[i] = normal_random(0.0, sigma);
    }
    this.bias = new Float32Array(this.n_classes);//zero init
  }

  train(features: number[][], labels: number[], train_idxs: number[], test_idxs: number[]) {
    for (let epoch = 0; epoch < this.epochs; epoch++) {
      console.log(`Epoch ${epoch}`);
      let epoch_result = this.train_one_epoch(features, labels, train_idxs, test_idxs);
      console.log(`Result: ${JSON.stringify(epoch_result)}`);
    }
  }

  export_model(): { weight: number[][], bias: number[] } {
    let weight: number[][] = [];
    let bias: number[] = [];
    for (let cls = 0; cls < this.n_classes; cls++) {
      let w = [];
      for (let d = 0; d < this.feature_dims; d++) {
        w.push(this.weight[d * this.n_classes + cls]);
      }
      weight.push(w);
      bias.push(this.bias[cls]);
    }
    return { weight, bias };
  }

  forward(feature: number[], prob_out: Float32Array = null): number {
    // x * W + b
    for (let cls = 0; cls < this.n_classes; cls++) {
      let sum = this.bias[cls];
      for (let d = 0; d < this.feature_dims; d++) {
        sum += feature[d] * this.weight[d * this.n_classes + cls];
      }
      prob_out[cls] = sum;
    }

    // softmax
    let max = -Infinity;
    let max_cls = 0;//classification result
    for (let cls = 0; cls < this.n_classes; cls++) {
      if (prob_out[cls] > max) {
        max = prob_out[cls];
        max_cls = cls;
      }
    }
    let expsum = 0.0;
    for (let cls = 0; cls < this.n_classes; cls++) {
      let exp = Math.exp(prob_out[cls] - max);
      prob_out[cls] = exp;
      expsum += exp;
    }
    for (let cls = 0; cls < this.n_classes; cls++) {
      prob_out[cls] /= expsum;
    }

    return max_cls;
  }

  private update_one(feature: number[], label: number): number {
    // returns softmax cross entropy loss
    let softmax = new Float32Array(this.n_classes);
    this.forward(feature, softmax);
    let loss = -Math.log(softmax[label] + 1e-20);//avoid NaN

    // calculate gradient
    softmax[label] -= 1;
    let delta_b = new Float32Array(this.n_classes);
    delta_b.set(softmax);
    let delta_w = new Float32Array(this.feature_dims * this.n_classes);
    for (let d = 0; d < this.feature_dims; d++) {
      for (let cls = 0; cls < this.n_classes; cls++) {
        delta_w[d * this.n_classes + cls] = feature[d] * softmax[cls];
      }
    }
    // update
    for (let i = 0; i < delta_b.length; i++) {
      this.bias[i] = -delta_b[i] * this.lr + this.bias[i];
    }
    for (let i = 0; i < delta_w.length; i++) {
      this.weight[i] = -delta_w[i] * this.lr + this.weight[i] * (1.0 - this.decay);
    }

    return loss;
  }

  private train_one_epoch(features: number[][], labels: number[], train_idxs: number[], test_idxs: number[]) {
    let train_idxs_shuffle = train_idxs.slice();
    shuffle(train_idxs_shuffle);
    let loss_sum = 0.0;
    for (let i = 0; i < train_idxs_shuffle.length; i++) {
      loss_sum += this.update_one(features[train_idxs_shuffle[i]], labels[train_idxs_shuffle[i]]);
    }
    let loss_avg = loss_sum / train_idxs_shuffle.length;

    let accuracy_sum = 0.0;
    let work = new Float32Array(this.n_classes);
    for (let i = 0; i < test_idxs.length; i++) {
      let pred_label = this.forward(features[test_idxs[i]], work);
      if (pred_label === labels[test_idxs[i]]) {
        accuracy_sum++;
      }
    }
    let accuracy_avg = accuracy_sum / test_idxs.length;

    return { train_loss: loss_avg, test_accuracy: accuracy_avg }
  }
}
