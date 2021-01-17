
import QtQuick 2.15
import RDHM 1.0

Item {
    width: ListView.view.width
    height: childrenRect.height

    Row {
        spacing: 5

        Rectangle {
            id: agentType

            width: 20
            height: 20

            radius: 10
            color: {
                switch(agentDetectionType) {
                    case AgentInformation.ZeroConf: return "yellow";
                    case HealthEnum.GOOD: return "brown";
                    default: return "silver";
                }
            }
        }

        Image {
            id: statusIndicator
            width: 20
            height: 20
            smooth: true
            sourceSize.width: 20
            sourceSize.height: 20
            source: {
                switch(agentHealth) {
                    case HealthEnum.UNKNOWN: return "question-mark.svg";
                    case HealthEnum.GOOD: return "check.svg";
                    case HealthEnum.BAD: return "close.svg";
                    case HealthEnum.CHECK_STATUS: return "warning.svg";
                    default: return "question-mark.svg";
                }
             }
        }

        Text {
            text: agentName

            anchors.verticalCenter: statusIndicator.verticalCenter
        }
    }
}
