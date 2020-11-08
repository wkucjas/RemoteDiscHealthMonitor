
import QtQuick 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    property alias label: label.text
    property alias model: agentsList.model

    Text {
        id: label

        Layout.alignment: Qt.AlignHCenter
        Layout.fillWidth: false

        font.pixelSize: 12
    }

    ListView {
        id: agentsList

        Layout.fillWidth: true
        Layout.fillHeight: true

        delegate: AgentDelegate {}
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
