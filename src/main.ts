// Modules to control application life and create native browser window
import { app, BrowserWindow, ipcMain } from "electron";
import * as fs from "fs";
import { resolve } from "path";
import { shuffle, permutation } from "./util";
import { Classifier } from "./classifier";

// Keep a global reference of the window object, if you don't, the window will
// be closed automatically when the JavaScript object is garbage collected.
let mainWindow: BrowserWindow;

function createWindow() {
  // Create the browser window.
  mainWindow = new BrowserWindow({ width: 800, height: 600 })

  // and load the index.html of the app.
  mainWindow.loadFile('static/index.html')

  // Open the DevTools.
  // mainWindow.webContents.openDevTools()

  // Emitted when the window is closed.
  mainWindow.on('closed', function () {
    // Dereference the window object, usually you would store windows
    // in an array if your app supports multi windows, this is the time
    // when you should delete the corresponding element.
    mainWindow = null
  })
}

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on('ready', createWindow)

// Quit when all windows are closed.
app.on('window-all-closed', function () {
  // On OS X it is common for applications and their menu bar
  // to stay active until the user quits explicitly with Cmd + Q
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', function () {
  // On OS X it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (mainWindow === null) {
    createWindow()
  }
})

// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and require them here.

ipcMain.on("load-image", (event: any, path: string) => {
  let image_rawdata = fs.readFileSync(path);
  let image_base64 = "data:image/jpeg;base64," + image_rawdata.toString("base64");
  event.sender.send("image-loaded", image_base64);
  console.log("sent image");
});

// better design pattern?
let extract_feature_expected_key: number;
let extract_feature_resolve: Function;
let extract_feature_reject: Function;
ipcMain.on("extracted-feature", (event: any, image_key: number, features: number[][]) => {
  if (image_key === extract_feature_expected_key) {
    extract_feature_resolve(features);
  } else {
    extract_feature_reject(`image key mismatch: ${image_key} !== ${extract_feature_expected_key}`);
  }
});
async function extract_feature(image_key: number, image_base64: string): Promise<number[][]> {
  mainWindow.webContents.send("extract-feature", image_key, image_base64);
  return new Promise<number[][]>((resolve, reject) => {
    extract_feature_expected_key = image_key;
    extract_feature_resolve = resolve;
    extract_feature_reject = reject;
  });
}

function save_json(path: string, obj: any) {
  fs.writeFileSync(path, JSON.stringify(obj), "utf8");
}

function load_json(path: string): any {
  return JSON.parse(fs.readFileSync(path, "utf8"));
}

let work_root = "/Users/hidaka/miljs/idnn/work1";

interface DatasetFiles {
  labels: [number, string][];
  imgid2label: number[];
  imgid2path: string[];
}

ipcMain.on("batch-extraction", async (event: any) => {
  console.log("batch extraction start");
  // entrypoint of batch feature extraction
  let files_data = load_json(work_root + "/files.json") as DatasetFiles;
  let all_features = [];
  let feature_imgids = [];
  for (let imgid = 0; imgid < files_data.imgid2path.length; imgid++) {
    let imgpath = files_data.imgid2path[imgid];
    console.log(imgpath);
    let image_rawdata = fs.readFileSync(work_root + "/" + imgpath);
    let image_base64 = "data:image/jpeg;base64," + image_rawdata.toString("base64");
    let features = await extract_feature(imgid, image_base64);
    for (let i = 0; i < features.length; i++) {
      all_features.push(features[i]);
      feature_imgids.push(imgid);
    }
  }
  save_json(work_root + "/feature_imgids.json", feature_imgids);
  save_json(work_root + "/features.json", all_features);
  console.log("batch extraction finished");
});


ipcMain.on("training", async (event: any) => {
  try {
    console.log("start training");
    let all_features = load_json(work_root + "/features.json") as number[][];
    let feature_imgids = load_json(work_root + "/feature_imgids.json") as number[];

    let files_data = load_json(work_root + "/files.json") as DatasetFiles;

    let n_images = files_data.imgid2label.length;
    let n_train = (n_images * 0.8) | 0;
    let perm_imgids = permutation(n_images);//imgids in top n_train elements are for training
    let train_imgids = new Set(perm_imgids.slice(0, n_train));
    // let test_imgids = new Set(perm_imgids.slice(n_train));
    let train_idxs: number[] = [];
    let test_idxs: number[] = [];
    let sample_labels: number[] = [];
    for (let idx = 0; idx < feature_imgids.length; idx++) {
      let imgid = feature_imgids[idx];
      sample_labels.push(files_data.imgid2label[imgid]);
      if (train_imgids.has(imgid)) {
        train_idxs.push(idx);
      } else {
        test_idxs.push(idx);
      }
    }

    let classifier = new Classifier(512, files_data.labels.length);
    classifier.train(all_features, sample_labels, train_idxs, test_idxs);
    console.log("exporting model");
    let model_params = classifier.export_model();
    save_json(work_root + "/weight.json", model_params);
    console.log("done");
  } catch (ex) {
    console.error(ex.stack);
  }
});
