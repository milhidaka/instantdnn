"""
SqueezeNet pretrained modelをchainer向けに変換
Download:
https://github.com/DeepScale/SqueezeNet/raw/master/SqueezeNet_v1.1/squeezenet_v1.1.caffemodel
"""

import sys
import os
import numpy as np
import pickle
import argparse
import chainer
import chainer.links.caffe


class SqueezeNetFeatureExtactor(chainer.Chain):
    def __init__(self, pretrained_caffemodel_path="resource/model/squeezenet_v1.1.caffemodel"):
        super().__init__()
        self.mean = np.array([104., 117., 123.], dtype=np.float32)[:, np.newaxis, np.newaxis]  # BGR
        with self.init_scope():
            self.caffe_func = chainer.links.caffe.CaffeFunction(pretrained_caffemodel_path)

    def __call__(self, x: chainer.Variable):
        conv9, = self.caffe_func(inputs={"data": x}, outputs=["fire9/concat"])  # (batch, 512, 13, 13)
        return chainer.functions.reshape(chainer.functions.average_pooling_2d(conv9, 13), (-1, 512))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("caffemodel")
    parser.add_argument("dst")
    args = parser.parse_args()
    model = SqueezeNetFeatureExtactor(args.caffemodel)
    with open(args.dst, "wb") as f:
        pickle.dump(model, f, protocol=pickle.HIGHEST_PROTOCOL)


if __name__ == "__main__":
    main()
