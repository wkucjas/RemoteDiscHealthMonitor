import QtQuick.Layouts 1.15
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property alias label: label.title
    property alias model: agentsList.model

    clip: true

    GroupBox {
        id: label
        anchors.fill: parent
        spacing: 2

        ListView {
            id: agentsList
            anchors.fill: parent

            delegate: AgentDelegate {
                MouseArea{
                anchors.fill: parent
                onDoubleClicked:{
                    switchAgentsListViewAndAgentDetailsView()
                }
                }
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


/*##^##
Designer {
    D{i:0;height:237;width:640}
}
##^##*/
