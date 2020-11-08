
import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: mainView
    width: 200
    height: 420

    ColumnLayout {
        id: column
        anchors.fill: parent

        AgentsView {
            id: discoveredAgentsView
            objectName: "activeAgents"

            Layout.fillWidth: true
            Layout.fillHeight: true

            label: qsTr("Discovered agents:")
        }

        AgentsView {
            id: hardcodedAgentsView

            Layout.fillWidth: true
            Layout.fillHeight: true

            label: qsTr("Hardcoded agents:")
        }

        Button {
            id: button
            text: qsTr("Add agent...")
        }
    }
}


