"""
特徴量から画像分類モデル学習
"""

import os
import numpy as np
import pickle
import argparse
import sklearn.svm
from sklearn_porter import Porter


def load_model(process_dir: str):
    with open(os.path.join(process_dir, "model.bin"), "rb") as f:
        return pickle.load(f)


def export_model(output_dir: str, model):
    porter = Porter(model, language="js")
    script = porter.export(embed_data=True)
    with open(os.path.join(output_dir, "classifier.js"), "w") as f:
        f.write(script)


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
