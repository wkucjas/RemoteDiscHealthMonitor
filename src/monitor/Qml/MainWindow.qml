
import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    id: mainView

    ColumnLayout {
        id: column
        anchors.fill: parent

        AgentsView {
            objectName: "activeAgents"

            Layout.fillWidth: true
            Layout.fillHeight: true

            label: qsTr("Discovered agents:")
        }

        AgentsView {

            Layout.fillWidth: true
            Layout.fillHeight: true

            label: qsTr("Hardcoded agents:")
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
