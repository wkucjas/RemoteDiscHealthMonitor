
import QtQuick 2.15

Item {
    property int buttonSize: 25
    property string imageSource
    property alias containsMouse: mouseArea.containsMouse

    signal buttonClicked()

    width:  buttonSize * 1.5
    height: buttonSize * 1.5

    Image {

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        width:  buttonSize
        height: buttonSize

        source: imageSource
        scale: mouseArea.containsMouse? 1.5: 1.0

        Behavior on opacity { PropertyAnimation{} }
        Behavior on scale   { PropertyAnimation{ duration: 100 } }

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            hoverEnabled: true

            onClicked: {
                buttonClicked();
            }
        }
    }
}
