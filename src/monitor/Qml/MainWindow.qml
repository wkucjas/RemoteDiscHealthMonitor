
import QtQuick 2.15

Item {
    ListView {
        id: listView
        objectName: "activeAgents"

        anchors.fill: parent

        delegate: Item {
            x: 5
            width: 80
            height: 40

            Text {
                text: agentName
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1}
}
##^##*/
