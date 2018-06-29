"""
識別機とメタデータをjsファイルに出力
"""

import os
import numpy as np
import pickle
import argparse
import json
import sklearn.svm


def load_model(process_dir: str):
    with open(os.path.join(process_dir, "model.bin"), "rb") as f:
        return pickle.load(f)


def export_model(output_dir: str, model):
    with open("resource/template/instantdnn.js") as f:
        js_template = f.read()
    weight_list = model.coef_.tolist()
    bias_list = model.intercept_.tolist()
    js_template = js_template.replace("\"INSTANTDNN_WEIGHT\"", json.dumps(weight_list))
    js_template = js_template.replace("\"INSTANTDNN_BIAS\"", json.dumps(bias_list))
    model_dir = os.path.join(output_dir, "instantdnn", "model")
    os.makedirs(model_dir, exist_ok=True)
    with open(os.path.join(model_dir, "instantdnn.js"), "w") as f:
        f.write(js_template)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("work")
    args = parser.parse_args()
    work_dir = args.work
    process_dir = os.path.join(work_dir, "process")
    output_dir = os.path.join(work_dir, "output")
    os.makedirs(output_dir, exist_ok=True)
    model = load_model(process_dir)
    export_model(output_dir, model)


if __name__ == "__main__":
    main()
