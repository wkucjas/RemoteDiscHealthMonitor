
import QtQuick 2.15

Item {
    id: deletionItem

    width: confirmation.width
    height: confirmation.height
    clip: true

    signal deleteItem()

    ImageButton {
        id: trash

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        opacity: delegateMouseArea.containsMouse || trash.containsMouse? 1.0: 0.0

        buttonSize: 25
        imageSource: "trash.svg"

        onButtonClicked: {
            deletionItem.state = "Confirmation";
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
                deleteItem();
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
