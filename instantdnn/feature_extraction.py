"""
特徴抽出
"""

import sys
import os
import yaml
import argparse
import pickle
import glob
import hashlib
import numpy as np
import chainer
import chainercv.utils
import chainercv.transforms
import chainercv.links.model.resnet


def load_config(work_dir: str):
    with open(os.path.join(work_dir, "instantdnn.yaml")) as f:
        return yaml.load(f)


class FeatureExtractor:
    def __init__(self, output_dir: str):
        self.output_dir = output_dir
        self.model = chainercv.links.model.resnet.ResNet50(pretrained_model="imagenet", arch="he")
        self.model.pick = "pool5"  # =>2048dim

    def extract(self, image_iterator):
        feats = []
        params_all = []
        with chainer.using_config("train", False):
            with chainer.using_config("enable_backprop", False):
                for image, params in image_iterator:
                    # TODO: バッチで抽出
                    feat = self.model(image[np.newaxis, ...] - self.model.mean)  # (1, 2048)
                    feats.append(feat.data[0, ...])
                    params_all.append(params)
        np.save(os.path.join(self.output_dir, "feat.npy"), np.array(feats, dtype=np.float32))
        with open(os.path.join(self.output_dir, "feat_params.bin"), "wb") as f:
            pickle.dump(params_all, f, protocol=pickle.HIGHEST_PROTOCOL)


class ImageLoader:
    def __init__(self, work_dir: str, config: dict):
        self.work_dir = work_dir
        self.config = config

    def __iter__(self):
        for label_info in self.config["labels"]:
            file_paths = []
            for ext in ["jpg", "jpeg", "png", "gif"]:
                file_paths.extend(glob.glob(os.path.join(self.work_dir, label_info["dir"], "*." + ext)))
            for file_path in file_paths:
                file_instance_id = hashlib.md5(file_path.encode("utf-8")).hexdigest()  # augmentaionにかかわらず1つの画像を示すなんらかのID
                for image, augment_params in self._load_augment_image(file_path):
                    yield image, {"label": label_info["id"], "instance": file_instance_id, "augment": augment_params}

    def _load_augment_image(self, path: str):
        image_raw = chainercv.utils.read_image(path)  # type: np.ndarray
        augment_params = {}
        image = chainercv.transforms.resize(image_raw, (224, 224))
        yield image, augment_params
        augment_params = {"flip": True}
        image = image[:, :, ::-1]
        yield image, augment_params


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("work")
    args = parser.parse_args()
    work_dir = args.work
    feature_output_dir = os.path.join(work_dir, "process")
    os.makedirs(feature_output_dir, exist_ok=True)
    config = load_config(work_dir)
    image_loader = ImageLoader(work_dir, config)
    extractor = FeatureExtractor(feature_output_dir)
    extractor.extract(image_loader)


if __name__ == "__main__":
    main()
