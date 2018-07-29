import { ipcRenderer } from "electron";
declare const WebDNN: any;
let runner: any;

async function load_webdnn() {
  try {
    runner = await WebDNN.load("../resource/assets/instantdnn/common/graph_descriptor");
    alert(runner.backendName);
  } catch (ex) {
    alert(ex);
  }
}

load_webdnn();

function augmentimage() {
  let prep_canvas = document.getElementById("prepare-image") as HTMLCanvasElement;
  let left = Math.random() * (256 - 224 + 1) | 0;
  let top = Math.random() * (256 - 224 + 1) | 0;
  let mirror = Math.random() >= 0.5;
  let dst_canvas = document.getElementById("dnn-input-image") as HTMLCanvasElement;
  let dst_ctx = dst_canvas.getContext("2d");
  dst_ctx.save();
  if (mirror) {
    dst_ctx.translate(224, 0);
    dst_ctx.scale(-1, 1);
  }
  dst_ctx.drawImage(prep_canvas, left, top, 224, 224, 0, 0, 224, 224);
  dst_ctx.restore();
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
    let image = runner.inputs[0]; 
    let feat = runner.outputs[0];
    image.set(await WebDNN.Image.getImageArray(document.getElementById("dnn-input-image") as HTMLCanvasElement));

    // Run
    await runner.run(); 

    alert("feat: " + feat.toActual()[0]);
  };
});

ipcRenderer.on("image-loaded", (event: any, image_base64: string) => {
  let canvas = document.getElementById("prepare-image") as HTMLCanvasElement;
  let ctx = canvas.getContext("2d");
  let img = new Image();
  img.onload = () => {
    ctx.drawImage(img, 0, 0, 256, 256);
  }
  img.src = image_base64;
});
