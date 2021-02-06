
import QtQuick 2.15

Item {
    property string imageSource
    property alias containsMouse: mouseArea.containsMouse

    signal buttonClicked()

    Image {

        anchors.fill: parent

        source: imageSource
        scale: mouseArea.containsMouse? 1.0: 0.7

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
