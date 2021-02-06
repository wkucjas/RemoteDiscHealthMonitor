
import QtQuick 2.15


Row {
    id: row

    property int imageSize: 48
    property int imagesSpacing: 48

    signal accepted()
    signal ignored()

    height: imageSize
    width: childrenRect.width

    ImageButton {
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
        buttonSize: imageSize
        imageSource: "cancel.svg"

        onButtonClicked: {
            ignored();
        }
    }
}


