
import QtQuick 2.15

Item {
    id: deletionItem

    width: confirmation.width
    clip: true

    signal deleteItem()

    ImageButton {
        id: trash

        width:  parent.height
        height: parent.height

        y: 0
        anchors.right: parent.right

        opacity: delegateMouseArea.containsMouse || trash.containsMouse? 1.0: 0.0

        imageSource: "trash.svg"

        onButtonClicked: {
            deletionItem.state = "Confirmation";
        }
    }

    Confirmation {
        id: confirmation

        y: parent.height
        anchors.right: parent.right

        height: parent.height
        width:  parent.height * 2.5

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
                y: deletionItem.height
            }

            PropertyChanges {
                target: confirmation
                y: 0
            }
        }
    ]

    transitions: Transition {
        PropertyAnimation {
            targets: [trash, confirmation]
            properties: "y"
        }
    }
}
