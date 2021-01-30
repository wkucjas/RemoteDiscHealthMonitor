import QtQuick.Layouts 1.15
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property alias label: label.title
    property alias model: agentsList.model

    clip: true

    SystemPalette { id: currentPalette; colorGroup: SystemPalette.Active }

    GroupBox {
        id: label
        anchors.fill: parent
        spacing: 2

        ListView {
            id: agentsList
            anchors.fill: parent

            spacing: 2
            clip: true

            delegate: Item {
                id: delegateItem

                width: ListView.view.width
                height: agentDelegate.height

                AgentDelegate {
                    id: agentDelegate

                    anchors.left: parent.left

                    width: childrenRect.width
                    height: childrenRect.height
                }

                MouseArea {
                    id: delegateMouseArea
                    anchors.fill: parent

                    hoverEnabled: true

                    onDoubleClicked:{
                        switchAgentsListViewAndAgentDetailsView()
                    }

                    onClicked: {
                        agentsList.currentIndex = index
                    }
                }

                Image {
                    id: trash

                    anchors.right: parent.right
                    anchors.rightMargin: 10
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
                    }
                }
            }

            highlight: Rectangle {
                opacity: 0.5
                color: currentPalette.highlight
                radius: 5
                z: -1
            }
        }

        ColumnLayout {

            Button {
                id: agentDetailsBackBtn
                visible: false
                text: "<<"
                onClicked: {
                    switchAgentsListViewAndAgentDetailsView()
                }
            }

            ComboBox {
                id: agentDetailsDisksComboBox
                width: label.width - 25
                visible: false
                model: ["Disk1", "Disk2", "Disk3"]
            }
        }
    }

    function switchAgentsListViewAndAgentDetailsView() {
        agentsList.visible = !agentsList.visible
        agentDetailsBackBtn.visible = !agentDetailsBackBtn.visible
        agentDetailsDisksComboBox.visible = !agentDetailsDisksComboBox.visible
    }

}



