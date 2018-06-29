"""
モデル非依存のファイルを出力ディレクトリにコピーする
"""

import os
import distutils.dir_util
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("work")
    args = parser.parse_args()
    work_dir = args.work
    output_dir = os.path.join(work_dir, "output")
    os.makedirs(output_dir, exist_ok=True)
    distutils.dir_util.copy_tree("resource/assets", output_dir)


if __name__ == "__main__":
    main()
