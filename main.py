import sys
import instantdnn.feature_extraction
import instantdnn.train_classifier
import instantdnn.export_classifier
import instantdnn.export_assets


def main():
    cmd = sys.argv.pop(1)
    if cmd == "feature_extraction":
        instantdnn.feature_extraction.main()
    elif cmd == "train_classifier":
        instantdnn.train_classifier.main()
    elif cmd == "export_classifier":
        instantdnn.export_classifier.main()
    elif cmd == "export_assets":
        instantdnn.export_assets.main()
    elif cmd == "all":
        instantdnn.export_assets.main()
        instantdnn.feature_extraction.main()
        instantdnn.train_classifier.main()
        instantdnn.export_classifier.main()
    else:
        raise NotImplementedError("Unknown command")


if __name__ == "__main__":
    main()
