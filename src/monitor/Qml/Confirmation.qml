
import QtQuick 2.15


Item {
    id: row

    signal accepted()
    signal ignored()

    ImageButton {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left

        width:  parent.height
        height: parent.height

        imageSource: "ok.svg"

        onButtonClicked: {
            accepted();
        }
    }

    ImageButton {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right

        width:  parent.height
        height: parent.height

        imageSource: "cancel.svg"

        onButtonClicked: {
            ignored();
        }
    }
}
