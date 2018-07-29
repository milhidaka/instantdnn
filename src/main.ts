// Modules to control application life and create native browser window
import { app, BrowserWindow, ipcMain } from "electron";
import * as fs from "fs";
import { resolve } from "path";

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

let work_root = "/Users/hidaka/miljs/idnn/work1"
ipcMain.on("batch-extraction", async (event: any) => {
  console.log("batch extraction start");
  // entrypoint of batch feature extraction
  let files_data = JSON.parse(fs.readFileSync(work_root + "/files.json", "utf8"));
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
  fs.writeFileSync(work_root + "/feature_imgids.json",
    JSON.stringify(feature_imgids), "utf8");
  fs.writeFileSync(work_root + "/features.json",
    JSON.stringify(all_features), "utf8");
    console.log("batch extraction finished");
});
