declare const WebDNN: any;

async function do_fetch() {
  alert("start fetch");
  try {
    let x = await fetch("../index.js");
    let tx = await x.text();
    alert(tx);
  } catch (ex) {
    alert(ex);
  }
}

async function load_webdnn() {
  try {
    let runner = await WebDNN.load("../resource/assets/instantdnn/common/graph_descriptor");
    alert(runner.backendName);
  } catch (ex) {
    alert(ex);
  }
}

do_fetch();
load_webdnn();
