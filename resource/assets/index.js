let idnn = undefined;
let camera_enabled = false;

window.onload = async () => {
    idnn = new InstantDNN();
    await idnn.load("instantdnn/common/graph_descriptor");
    console.log(`Model loaded, backend=${idnn.get_backend()}`);

    document.getElementById("loadimage").onclick = async () => {
        let imageData = await WebDNN.Image.getImageArray(document.getElementById("imageurl").value, {dstW: 227, dstH: 227});
        WebDNN.Image.setImageArrayToCanvas(imageData, 227, 227, document.getElementById('target'));
    }

    document.getElementById("start_classify").onclick = async () => {
        let begin = Date.now();
        let probs = await idnn.classify_from_canvas(document.getElementById('target'));
        let end = Date.now();
        let result = "";
        for (let i = 0; i < probs.length; i++) {
            result += `${idnn.labels[i]}: ${probs[i] * 100 | 0}% `;
        }
        result += `(${end - begin}ms)`;
        document.getElementById("result").innerText = result;
    }

    document.getElementById("start_camera").onclick = async () => {
        navigator.getUserMedia({ audio: false, video: { width: 227, height: 227 } },
            function(stream) {
               var video = document.getElementById('camera');
               video.src = window.URL.createObjectURL(stream);
               video.onloadedmetadata = function(e) {
                 video.play();
                 camera_enabled = true;
                 setInterval(classify_from_camera, 1000);
               };
            },
            function(err) {
               console.log("The following error occurred: " + err.name);
            }
         );
    }

    let classify_from_camera = () => {
        var video = document.getElementById("camera");
        var canvas = document.getElementById("target");
        var context = canvas.getContext("2d");
        context.drawImage(video, 0, 0, 227, 227);
        document.getElementById("start_classify").click();
    }
}
