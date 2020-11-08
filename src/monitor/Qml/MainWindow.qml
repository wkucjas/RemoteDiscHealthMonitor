
import QtQuick 2.15

Item {
    id: mainView

    Rectangle {
        id: zeroConfContainer

        height: childrenRect.height

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        Text {
            id: zeroConfLabel
            text: qsTr("Discovered agents:")
            anchors.top: parent.top
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ListView {
            id: zeroConfList
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: zeroConfLabel.bottom
            anchors.bottom: parent.bottom
            objectName: "activeAgents"

            delegate: AgentDelegate {}
        }
    }

    Rectangle {
        id: hardcodedContainer
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: zeroConfContainer.bottom
        anchors.bottom: parent.bottom

        Text {
            id: hardcodedLabel
            text: qsTr("Hardcoded agents:")
            anchors.top: parent.top
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ListView {
            id: hardcodedList
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: hardcodedLabel.bottom
            anchors.bottom: parent.bottom

            objectName: "hardcodedActiveAgents"

            delegate: AgentDelegate {}
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
