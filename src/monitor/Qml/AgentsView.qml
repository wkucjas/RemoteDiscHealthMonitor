
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
                    agentsList.visible = false
                }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;height:237;width:640}
}
##^##*/
