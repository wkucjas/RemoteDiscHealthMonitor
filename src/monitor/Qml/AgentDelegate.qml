
import QtQuick 2.15
import RDHM 1.0

    Row {
        property int imagesSize: 20

        spacing: 5

        Image {
            id: agentType

            width: imagesSize
            height: imagesSize
            smooth: true
            sourceSize.width: imagesSize
            sourceSize.height: imagesSize

            source: {
                switch(agentDetectionType) {
                    case AgentInformation.ZeroConf: return "hard-disk.svg";
                    case HealthEnum.GOOD: return "hard-disk2.svg";
                    default: return "hard-disc2.svg";
                    }
            }
        }

        Image {
            id: statusIndicator

            width: imagesSize
            height: imagesSize
            smooth: true
            sourceSize.width: imagesSize
            sourceSize.height: imagesSize

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
