import { ipcRenderer } from "electron";
import { resolve } from "url";
declare const WebDNN: any;
let runner: any;
const raw_image_size = 256;
const dnn_image_size = 227;

async function load_webdnn() {
  try {
    runner = await WebDNN.load("../resource/assets/instantdnn/common/graph_descriptor");
    alert(runner.backendName);
  } catch (ex) {
    alert(ex);
  }
}

load_webdnn();

function set_image(image_base64: string): Promise<void> {
  return new Promise((resolve, reject) => {
    let canvas = document.getElementById("prepare-image") as HTMLCanvasElement;
    let ctx = canvas.getContext("2d");
    let img = new Image();
    img.onload = () => {
      ctx.drawImage(img, 0, 0, raw_image_size, raw_image_size);
      resolve();
    }
    img.src = image_base64;
  });
}

function augmentimage() {
  let prep_canvas = document.getElementById("prepare-image") as HTMLCanvasElement;
  let left = Math.random() * (raw_image_size - dnn_image_size + 1) | 0;
  let top = Math.random() * (raw_image_size - dnn_image_size + 1) | 0;
  let mirror = Math.random() >= 0.5;
  let dst_canvas = document.getElementById("dnn-input-image") as HTMLCanvasElement;
  let dst_ctx = dst_canvas.getContext("2d");
  dst_ctx.save();
  if (mirror) {
    dst_ctx.translate(dnn_image_size, 0);
    dst_ctx.scale(-1, 1);
  }
  dst_ctx.drawImage(prep_canvas, left, top, dnn_image_size, dnn_image_size, 0, 0, dnn_image_size, dnn_image_size);
  dst_ctx.restore();
}

async function extract_feature(): Promise<Float32Array> {
  let image = runner.inputs[0]; 
  let feat = runner.outputs[0];
  image.set(await WebDNN.Image.getImageArray(document.getElementById("dnn-input-image") as HTMLCanvasElement,{
    order: WebDNN.Image.Order.CHW,
    color: WebDNN.Image.Color.BGR,
    bias: [123.68, 116.779, 103.939]
  }));

  // Run
  await runner.run(); 

  return feat.toActual();
}

window.addEventListener("load", (event) => {
  document.getElementById("loadimage").onclick = () => {
    let path = "/Users/hidaka/miljs/idnn/work1/cup/image_0001.jpg";
    ipcRenderer.send("load-image", path);
  };
  document.getElementById("augmentimage").onclick = () => {
    augmentimage();
  };
  document.getElementById("extractfeat").onclick = async () => {
    let feat = await extract_feature();
    alert(`feat[0] = ${feat[0]}`);
  };
  document.getElementById("batchextract").onclick = () => {
    // start batch extraction
    ipcRenderer.send("batch-extraction");
  };
});

ipcRenderer.on("image-loaded", (event: any, image_base64: string) => {
  set_image(image_base64);
});

ipcRenderer.on("extract-feature", async (event: any, image_key: any, image_base64: string) => {
  await set_image(image_base64);
  let feats = [];
  for (let i = 0; i < 10; i++) {
    augmentimage();
    let feat = await extract_feature();
    feats.push(Array.from(feat));
  }
  
  ipcRenderer.send("extracted-feature", image_key, feats);
});

