
import QtQuick 2.15
import RDHM 1.0

Item {
    width: ListView.view.width
    height: childrenRect.height

    Row {
        spacing: 5

        Rectangle {
            id: statusIndicator
            width: 20
            height: 20

            radius: 10
            color: {
                switch(agentHealth) {
                    case HealthEnum.UNKNOWN: return "blue";
                    case HealthEnum.GOOD: return "green";
                    case HealthEnum.BAD: return "red";
                    case HealthEnum.CHECK_STATUS: return "orange";
                    default: return "silver";
                }
            }
        }

        Text {
            text: agentName

            anchors.verticalCenter: statusIndicator.verticalCenter
        }
    }
}
