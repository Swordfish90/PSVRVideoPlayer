import QtQuick 2.0
import QtCanvas3D 1.1

import "glcode.js" as GLCode

Item {
    property Item textureSource

    Canvas3D {
        id: canvas3d

        anchors.fill: parent

        onInitializeGL: {
            GLCode.initializeGL(canvas3d, textureSource, qmlpsvr);
        }

        onPaintGL: {
            GLCode.paintGL(canvas3d);
        }

        onResizeGL: {
            GLCode.resizeGL(canvas3d);
        }

        visible: false
    }

    LensDistortedView {
        anchors { left: parent.left; top: parent.top; bottom: parent.bottom }
        width: parent.width * 0.5

        source: ShaderEffectSource {
            sourceItem: canvas3d
            mipmap: false
            sourceRect: Qt.rect(0, 0, canvas3d.width * 0.5, canvas3d.height)
        }
    }

    LensDistortedView {
        anchors { right: parent.right; top: parent.top; bottom: parent.bottom }
        width: parent.width * 0.5

        source: ShaderEffectSource {
            sourceItem: canvas3d
            mipmap: false
            sourceRect: Qt.rect(canvas3d.width * 0.5, 0, canvas3d.width * 0.5, canvas3d.height)
        }
    }
}
