"""
特徴量から画像分類モデル学習
"""

import os
import numpy as np
import pickle
import argparse
import sklearn.svm
import sklearn.model_selection


def load_dataset(feature_dir: str):
    feats = np.load(os.path.join(feature_dir, "feat.npy"))
    with open(os.path.join(feature_dir, "feat_params.bin"), "rb") as f:
        feat_params = pickle.load(f)
    labels = []
    groups = []
    group_mapping = {}
    group_mapping_next = 0
    for feat_param in feat_params:
        labels.append(feat_param["label"])
        instance = feat_param["instance"]
        # GroupKFoldで用いるインスタンスごとに一意のグループIDを割り振り
        if instance not in group_mapping:
            group_mapping[instance] = group_mapping_next
            group_mapping_next += 1
        groups.append(group_mapping[instance])
    assert len(feats) == len(labels)
    return feats, np.array(labels, dtype=np.int32), np.array(groups, dtype=np.int32)


def optimize_params(feats, labels, groups):
    group_kfold = sklearn.model_selection.GroupShuffleSplit(n_splits=3)
    best_c_score = -1.0
    best_c = 0.0
    best_model = None
    for c in [10.0, 1.0, 0.1, 0.01]:
        print("c", c)
        scores = []
        model = None
        for train_idxs, test_idxs in group_kfold.split(feats, groups=groups):
            model = sklearn.svm.LinearSVC(C=c)
            model.fit(feats[train_idxs], labels[train_idxs])
            score = model.score(feats[test_idxs], labels[test_idxs])
            print("score", score)
            scores.append(score)
        mean_score = np.mean(scores)
        if mean_score > best_c_score:
            best_c_score = mean_score
            best_c = c
            best_model = model
    print("best_c", best_c)
    return best_model


def save_model(process_dir, model):
    with open(os.path.join(process_dir, "model.bin"), "wb") as f:
        pickle.dump(model, f, protocol=pickle.HIGHEST_PROTOCOL)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("work")
    args = parser.parse_args()
    work_dir = args.work
    process_dir = os.path.join(work_dir, "process")
    feats, labels, groups = load_dataset(process_dir)
    model = optimize_params(feats, labels, groups)
    save_model(process_dir, model)


if __name__ == "__main__":
    main()
