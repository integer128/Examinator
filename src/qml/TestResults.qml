import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {
    id: testResults_page

    header: ToolBar {
        height: 40

        ToolButton {
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter

            Text {
                text: "Back"
                font.pixelSize: 16
                anchors.centerIn: parent
            }

            onClicked: {
                stackView.pop();
            }
        }
    }

    ColumnLayout {
        id: colLayout_
        anchors.fill: parent

        ListView {
            id: testResultView
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 20
            clip: true
            model: tr_model

            delegate: Pane {
                id: test_row
                Material.elevation: 1
                Layout.alignment: Qt.AlignLeft
                width: parent.width
                height: 180

                Column {
                    spacing: 2

                    Label {
                        text: "STUDENT ID: " + trid
                        color: "#ffffff"
                        font.pixelSize: 24
                    }

                    Label {
                        text: "RESULT: " + trresult
                        color: "#ffffff"
                        font.pixelSize: 24
                    }

                    Label {
                        text: "DATE TIME: " + trdate
                        color: "#ffffff"
                        font.pixelSize: 24
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        tr_model.updateTable()
    }
}
