
import QtQuick 2.15


Row {
    id: row

    property int imageSize: 48
    property int imagesSpacing: 48

    signal accepted()
    signal ignored()

    height: imageSize
    width: childrenRect.width

    Image {
        width: imageSize
        height: imageSize

        source: "ok.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: accepted();
        }
    }

    Item {
        width: imagesSpacing
        height: imageSize
    }

    Image {
        width: imageSize
        height: imageSize

        source: "cancel.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: ignored();
        }
    }
}


