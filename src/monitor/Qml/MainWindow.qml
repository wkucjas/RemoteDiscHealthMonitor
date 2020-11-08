
import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    id: mainView

    ColumnLayout {
        id: column
        anchors.fill: parent

        ColumnLayout {
            id: zeroConfContainer

            Layout.fillWidth: true
            Layout.fillHeight: true

            Text {
                id: zeroConfLabel
                Layout.alignment: Qt.AlignHCenter
                Layout.fillWidth: false

                text: qsTr("Discovered agents:")
                font.pixelSize: 12
            }

            ListView {
                id: zeroConfList
                objectName: "activeAgents"

                Layout.fillWidth: true
                Layout.fillHeight: true

                delegate: AgentDelegate {}
            }
        }

        ColumnLayout {
            id: hardcodedContainer

            Layout.fillWidth: true
            Layout.fillHeight: true

            Text {
                id: hardcodedLabel

                Layout.alignment: Qt.AlignHCenter

                text: qsTr("Hardcoded agents:")
                font.pixelSize: 12
            }

            ListView {
                id: hardcodedList
                objectName: "hardcodedActiveAgents"

                Layout.fillWidth: true
                Layout.fillHeight: true

                delegate: AgentDelegate {}
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
