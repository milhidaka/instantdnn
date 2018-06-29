"""
WebDNNで特徴抽出モデルを変換
"""

import sys
import os
import numpy as np
import pickle
import argparse
import chainer
import chainercv.utils
import chainercv.transforms
import chainercv.links.model.resnet
from webdnn.backend import generate_descriptor
from webdnn.frontend.chainer import ChainerConverter


def export_feature_extractor(output_dir: str):
    model = chainercv.links.model.resnet.ResNet50(pretrained_model="imagenet", arch="he")
    model.pick = "pool5"  # =>2048dim
    with chainer.using_config("train", False):
        with chainer.using_config("enable_backprop", True):
            nn_input = chainer.Variable(np.zeros((1, 3, 224, 224), dtype=np.float32))
            nn_output = model(nn_input)
            graph = ChainerConverter().convert([nn_input], [nn_output])
    for backend in ["webgpu", "webgl", "webassembly"]:
        graph_exec_data = generate_descriptor(backend, graph, constant_encoder_name="eightbit")
        graph_exec_data.save(output_dir)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("work")
    args = parser.parse_args()
    work_dir = args.work
    output_dir = os.path.join(work_dir, "output", "graph_descriptor")
    os.makedirs(output_dir, exist_ok=True)
    export_feature_extractor(output_dir)


if __name__ == "__main__":
    # It seems stack size expansion is needed for deepcopy of graph (performed in webdnn)
    import threading

    sys.setrecursionlimit(10000)
    threading.stack_size(64 * 1024 * 1024)
    t = threading.Thread(target=main)
    t.start()
    t.join()
