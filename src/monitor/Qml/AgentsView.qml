import QtQuick.Layouts 1.15
import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt.labs.qmlmodels 1.0
import RDHM 1.0

Item {
    property alias label: label.title
    property alias model: agentsList.model

    clip: true

    SystemPalette { id: currentPalette; colorGroup: SystemPalette.Active }

    GroupBox {
        id: label
        anchors.fill: parent
        spacing: 2

        ListView {
            id: agentsList
            anchors.fill: parent

            spacing: 2
            clip: true

            delegate: Item {
                id: delegateItem

                width: ListView.view.width
                height: 30

                MouseArea {
                    id: delegateMouseArea
                    anchors.fill: parent

                    hoverEnabled: true

                    onDoubleClicked:{
                        switchAgentsListViewAndAgentDetailsView()
                    }

                    onClicked: {
                        agentsList.currentIndex = index

                        agentDetailsDisksComboBox.model = agentDiskInfoNames

                        agentDetailsDisksComboBox.smartVector = agentDiskInfoData
                    }

                    AgentDelegate {
                        id: agentDelegate

                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    DeletionItem {
                        id: deletionItem

                        visible: agentDetectionType == AgentInformation.Hardcoded
                        height: parent.height - 6
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        anchors.verticalCenter: parent.verticalCenter

                        onDeleteItem: {
                            agentsList.model.removeAgentAt(index);
                        }
                    }
                }
            }

            highlight: Rectangle {
                opacity: 0.5
                color: currentPalette.highlight
                radius: 5
                z: -1
            }
        }

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            anchors.rightMargin: 1
            anchors.leftMargin: 1
            anchors.bottomMargin: 1
            anchors.topMargin: 1

            Button {
                id: agentDetailsBackBtn
                visible: false
                width: 200
                height: 10
                text: "<<"
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                onClicked: {
                    switchAgentsListViewAndAgentDetailsView()
                }
            }

            ComboBox {
                id: agentDetailsDisksComboBox
                visible: false
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                property var smartVector: []
                property var stringList: []
                width: 150

                onVisibleChanged: {
                    fillSmartTable(currentIndex)
                }

                onCurrentIndexChanged: {
                    tableView.model.clear()
                    tableView.model.appendRow({
                            "attr": "Attribute Name",
                            "value": "Value",
                            "worst": "Worst",
                            "rawVal": "Raw Value",
                            "rawVal2": "Raw Value2"
                    })

                    fillSmartTable(currentIndex)
                }
            }

            TableView {
                id: tableView
                width: 600
                height: 300
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.rowSpan: 5
                Layout.columnSpan: 1
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                columnSpacing: 1
                rowSpacing: 1
                clip: false
                visible: false

                model: TableModel {
                    TableModelColumn { display: "attr" }
                    TableModelColumn { display: "value" }
                    TableModelColumn { display: "worst" }
                    TableModelColumn { display: "rawVal" }
                    TableModelColumn { display: "rawVal2" }

                    rows: [{
                            "attr": "Attribute Name",
                            "value": "Value",
                            "worst": "Worst",
                            "rawVal": "Raw Value",
                            "rawVal2": "Raw Value2"
                    }]
                }

                delegate: Rectangle {
                    implicitWidth: 150
                    implicitHeight: 20
                    border.width: 1

                    Text {
                        text: display
                        anchors.centerIn: parent
                    }
                }
            }
        }
    }

    function switchAgentsListViewAndAgentDetailsView() {
        agentsList.visible = !agentsList.visible
        agentDetailsBackBtn.visible = !agentDetailsBackBtn.visible
        agentDetailsDisksComboBox.visible = !agentDetailsDisksComboBox.visible
        tableView.visible = ! tableView.visible
    }

    function fillSmartTable( index)
    {
        agentDetailsDisksComboBox.stringList = (agentDetailsDisksComboBox.smartVector[index]).split(';');

        for(var i=0; i< agentDetailsDisksComboBox.stringList.length; i++)
        {
            console.log(agentDetailsDisksComboBox.stringList[i]);
            var data=(agentDetailsDisksComboBox.stringList[i]).split(',')
            tableView.model.appendRow({
                attr: data[0],
                value: data[1],
                worst: data[2],
                rawVal: data[3],
                rawVal2: data[4]
            })
        }
    }

}

