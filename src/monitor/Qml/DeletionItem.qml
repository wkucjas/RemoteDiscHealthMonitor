
import QtQuick 2.15

Item {
    id: deletionItem

    width: confirmation.width
    height: confirmation.height
    clip: true

    Image {
        id: trash

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        width: 25
        height: 25

        opacity: delegateMouseArea.containsMouse || trashMouseArea.containsMouse? 1.0: 0.0

        source: "trash.svg"
        scale: trashMouseArea.containsMouse? 1.5: 1.0

        Behavior on opacity { PropertyAnimation{} }
        Behavior on scale   { PropertyAnimation{ duration: 100 } }

        MouseArea {
            id: trashMouseArea
            anchors.fill: parent

            hoverEnabled: true

            onClicked: {
                deletionItem.state = "Confirmation"
            }
        }
    }

    Confirmation {
        id: confirmation

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -deletionItem.height

        imageSize: 20
        imagesSpacing: 15

        Connections {
            target: confirmation

            function onAccepted() {
                deletionItem.state = "Question";
            }

            function onIgnored() {
                deletionItem.state = "Question";
            }
        }
    }

    Connections {
        target: delegateMouseArea
        function onExited() {
            deletionItem.state = "Question";
        }
    }

    states: [
        State {
            name: "Question"
        },
        State {
            name: "Confirmation"

            PropertyChanges {
                target: trash
                anchors.verticalCenterOffset: deletionItem.height
            }

            PropertyChanges {
                target: confirmation
                anchors.verticalCenterOffset: 0
            }
        }
    ]

    transitions: Transition {
        PropertyAnimation {
            targets: [trash, confirmation]
            properties: "anchors.verticalCenterOffset"
        }
    }
}
