import QtQuick 2.7
import QtQuick.Window 2.2
import QtMultimedia 5.7

import QMLPSVR 0.1

import "utils.js" as Utils

Window {
    title: qsTr("PSVRVideoPlayer")
    width: 1280
    height: 768
    visible: true
    color: "black"

    Video {
        readonly property real seekOffset: 30 * 1000

        id: videoSource
        anchors.fill: parent
        width: metaData.resolution ? metaData.resolution.width : 0
        height: metaData.resolution ? metaData.resolution.height : 0
        fillMode: VideoOutput.Stretch
        autoPlay: true
        visible: false

        function togglePlay() {
            if (playbackState === MediaPlayer.PausedState) {
                play();
            } else {
                pause();
            }
        }

        function next() {
            seek(position + seekOffset);
        }

        function prev() {
            seek(position - seekOffset);
        }

        onErrorChanged: quitWithError("Error while playing video: " + errorString);
    }

    QMLPSVR {
        id: qmlpsvr

        Component.onCompleted: initialize();
        Component.onDestruction: terminate();
    }

    ShaderEffectSource {
        id: effectSource
        width: Utils.nearestPow2(videoSource.width)
        height: Utils.nearestPow2(videoSource.height)
        sourceItem: videoSource
        textureMirroring: ShaderEffectSource.NoMirroring
        visible: false
        mipmap: false
    }

    Loader {
        anchors.fill: parent
        sourceComponent: Component {
            Pano3DView {
                id: pano3dView
                anchors.fill: parent
                textureSource: effectSource
            }
        }
        active: qmlpsvr.initialized
    }

    Item {
        id: keyManager
        focus: true

        Keys.onPressed: {
            if (event.key === Qt.Key_Backspace) {
                qmlpsvr.resetSensors();
            } else if (event.key === Qt.Key_Space) {
                videoSource.togglePlay();
            } else if (event.key === Qt.Key_Left) {
                videoSource.prev();
            } else if (event.key === Qt.Key_Right) {
                videoSource.next();
            } else if (event.key === Qt.Key_Escape) {
                Qt.quit();
            }
        }
    }

    function quitWithError(msg) {
        console.log(msg);
        Qt.quit();
    }

    function init() {
        var filePath = Qt.application.arguments[1];
        if (!filePath) {
            quitWithError("Video file path is not valid.");
            return;
        }

        videoSource.source = "file://" + filePath;
        qmlpsvr.initialize();
    }

    Component.onCompleted: init();
    Component.onDestruction: qmlpsvr.terminate();
}
