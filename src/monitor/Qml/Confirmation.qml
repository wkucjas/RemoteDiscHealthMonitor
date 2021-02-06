
import QtQuick 2.15


Row {
    id: row

    property int imageSize: 48
    property int imagesSpacing: 48

    signal accepted()
    signal ignored()

    height: childrenRect.height
    width: childrenRect.width

    ImageButton {
        anchors.verticalCenter: parent.verticalCenter

        buttonSize: imageSize
        imageSource: "ok.svg"

        onButtonClicked: {
            accepted();
        }
    }

    Item {
        width: imagesSpacing
        height: imageSize
    }

    ImageButton {
        anchors.verticalCenter: parent.verticalCenter

        buttonSize: imageSize
        imageSource: "cancel.svg"

        onButtonClicked: {
            ignored();
        }
    }
}


