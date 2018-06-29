class InstantDNN {
    constructor() {
        this.runner = null;
        this._weight = "INSTANTDNN_WEIGHT";
        this._bias = "INSTANTDNN_BIAS";
    }

    async load(graph_descrptor_dir) {
        this.runner = await WebDNN.load(graph_descrptor_dir);
    }

    get_backend() {
        return this.runner.backendName;
    }

    async classify_from_canvas(canvas) {
        let x = this.runner.inputs[0];
        let y = this.runner.outputs[0];

        x.set(await WebDNN.Image.getImageArray(canvas, {
            order: WebDNN.Image.Order.CHW,
            color: WebDNN.Image.Color.BGR,
            bias: [123, 117, 104]
        }));

        await this.runner.run();

        let feature = y.toActual();

        let scores = this.calculate_score(feature);
        return scores;
    }

    calculate_score(feat) {
        let labels = this._weight.length;
        let dims = this._weight[0].length;
        let scores = [];
        for (let label = 0; label < labels; label++) {
            let sum = this._bias[label];
            let weight = this._weight[label];
            for (let dim = 0; dim < dims; dim++) {
                sum += feat[dim] * weight[dim];
            }
            scores.push(sum);
        }

        return scores;
    }
}
