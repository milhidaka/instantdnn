let idnn = undefined;

window.onload = async () => {
    idnn = new InstantDNN();
    await idnn.load("instantdnn/common/graph_descriptor");
    console.log(`Model loaded, backend=${idnn.get_backend()}`);

    document.getElementById("loadimage").onclick = async () => {
        let imageData = await WebDNN.Image.getImageArray(document.getElementById("imageurl").value, {dstW: 227, dstH: 227});
        WebDNN.Image.setImageArrayToCanvas(imageData, 227, 227, document.getElementById('target'));
    }

    document.getElementById("start_classify").onclick = async () => {
        let probs = await idnn.classify_from_canvas(document.getElementById('target'));
        let result = "";
        for (let i = 0; i < probs.length; i++) {
            result += `${idnn.labels[i]}: ${probs[i] * 100 | 0}% `;
        }
        document.getElementById("result").innerText = result;
    }
}
