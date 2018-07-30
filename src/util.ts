
export function shuffle(seq: any[]) {
  let length = seq.length;
  for (let i = 0; i < length; i++) {
    // random [i, length-1]
    let swap_to = (Math.random() * (length - i) + i) | 0;
    let tmp = seq[i];
    seq[i] = seq[swap_to];
    seq[swap_to] = tmp;
  }
}

export function permutation(length: number): number[] {
  let seq: number[] = [];
  for (let i = 0; i < length; i++) {
    seq.push(i);
  }

  shuffle(seq);

  return seq;
}

export function normal_random(mu: number=0, sigma: number=1) {
  let x = 1.0 - Math.random();//avoid 0
  let y = Math.random();
  let std_normal = Math.sqrt(-2.0 * Math.log(x)) * Math.cos(2 * Math.PI * y);
  return std_normal * sigma + mu;
}
