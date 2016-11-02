Qt.include("three.js")
Qt.include("StereoEffect.js")

var meshL, meshR;
var camera, scene;
var renderer, stereoEffect;

var geoL, geoR;

var quaternion;

function initializeGL(canvas, inputSource, qmlpsvr) {
    camera = new THREE.PerspectiveCamera(100, canvas.width / canvas.height, 1, 10000);
    scene = new THREE.Scene();

    // Left image
    geoL = new THREE.SphereGeometry(500, 128, 128);
    geoL.name = "geoL";
    geoL.applyMatrix(new THREE.Matrix4().makeScale(-1, 1, 1));

    var uvs = geoL.faceVertexUvs[0];
    for (i = 0; i < uvs.length; i ++) {
        for (j = 0; j < 3; j++) {
            uvs[i][j].x -= 0.25;
            uvs[i][j].y *= 0.5;
            uvs[i][j].y += 0.5;
        }
    }

    // Right image
    geoR = new THREE.SphereGeometry(500, 128, 128);
    geoR.name = "geoR";
    geoR.applyMatrix(new THREE.Matrix4().makeScale(-1, 1, 1));

    var uvs = geoR.faceVertexUvs[0];
    for (var i = 0; i < uvs.length; i++) {
        for (var j = 0; j < 3; j ++) {
            uvs[i][j].x -= 0.25;
            uvs[i][j].y *= 0.5;
        }
    }

    var texture = new THREE.QtQuickItemTexture(inputSource);
    texture.wrapS = THREE.RepeatWrapping;
    texture.wrapT = THREE.RepeatWrapping;

    var material = new THREE.MeshBasicMaterial({ map: texture });
    camera.updateProjectionMatrix();

    meshL = new THREE.Mesh(geoL, material);
    meshL.name = "meshL";
    meshL.layers.set(1);

    meshR = new THREE.Mesh(geoR, material);
    meshR.name = "meshR";
    meshR.layers.set(2);

    scene.add(meshL);
    scene.add(meshR);

    renderer = new THREE.Canvas3DRenderer({
        canvas: canvas,
        antialias: false,
        devicePixelRatio: canvas.devicePixelRatio
    });
    renderer.setSize(canvas.width, canvas.height);

    stereoEffect = new THREE.StereoEffect(renderer);
    stereoEffect.setSize(canvas.width, canvas.height);
}

function resizeGL(canvas) {
    camera.aspect = canvas.width / canvas.height;
    camera.updateProjectionMatrix();

    stereoEffect.setSize(canvas.width, canvas.height);
}

function paintGL(canvas) {
    qmlpsvr.updateSensorsData();
    quaternion = qmlpsvr.retrieveOrientation();
    camera.quaternion.set(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
    stereoEffect.render(scene, camera);
}
