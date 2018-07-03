import os
import yaml


def load_config(work_dir: str):
    with open(os.path.join(work_dir, "instantdnn.yaml")) as f:
        return yaml.load(f)
