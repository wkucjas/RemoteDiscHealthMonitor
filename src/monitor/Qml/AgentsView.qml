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
                height: 30

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

                    AgentDelegate {
                        id: agentDelegate

                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    DeletionItem {
                        id: deletionItem

                        height: parent.height
                        anchors.right: parent.right
                        anchors.rightMargin: 10

                        onDeleteItem: {
                            agentsList.model.removeAgentAt(index);
                        }
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



