import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {
    id: test_page

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
        id: columnLayout_
        anchors.fill: parent

        ListView {
            id: tests_listView
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 20
            clip: true
            model: qa_model

            delegate: Pane {
                id: test_row
                Material.elevation: 1
                Layout.alignment: Qt.AlignLeft
                width: parent.width
                height: 180

                Column {
                    spacing: 2

                    Label {
                        text: testquestion
                        color: "#ffffff"
                    }

                    RowLayout {

                        RadioButton {
                            id: radio_button1

                            onClicked: {
                                radio_button2.checked = false
                                radio_button3.checked = false
                                selectedanswer = 0
                            }
                        }

                        Label { text: testanswer1 }
                    }

                    RowLayout {

                        RadioButton {
                            id: radio_button2

                            onClicked: {
                                radio_button1.checked = false
                                radio_button3.checked = false
                                selectedanswer = 1
                            }
                        }

                        Label { text: testanswer2 }
                    }

                    RowLayout {

                        RadioButton {
                            id: radio_button3

                            onClicked: {
                                radio_button2.checked = false
                                radio_button1.checked = false
                                selectedanswer = 2
                            }
                        }

                        Label { text: testanswer3 }
                    }
                }
            }
        }

        Button {
            Layout.fillWidth: true
            height: 40
            flat: true

            background: Rectangle {
                id: rect_enter
                color: "#58E2A0"
                anchors.fill: parent

                Text {
                    text: "ЗАВЕРШИТЬ"
                    color: "#FFFFFF"
                    font.pixelSize: 14
                    font.family: "Open Sans"
                    font.styleName: "normal"
                    font.bold: true
                    anchors.centerIn: parent
                }
            }

            onHoveredChanged: hovered ? rect_enter.color = "#4FB483"
                                      : rect_enter.color = "#58E2A0"
            onPressedChanged: pressed ? rect_enter.color = "#31825B"
                                      : rect_enter.color = "#4FB483"

            onClicked: {
                qa_model.calculatePoints(auth.userId, qa_model.points_)
                columnLayout_.enabled = false
                result_rect.visible = true
            }
        }
    }

    Rectangle {
        id: result_rect
        height: parent.height
        width: parent.width
        color: Qt.rgba(255,255,255,0.9)
        visible: false;

        Column {
            spacing: 2

            Label {
                Layout.alignment: Qt.AlignCenter
                text: "Ваш результат"
                color: "black"
                font.pixelSize: 16
            }

            Label {
                Layout.alignment: Qt.AlignCenter
                text: "Количество набранных баллов: " + qa_model.points_
                color: "black"
                font.pixelSize: 16
            }

            Label {
                Layout.alignment: Qt.AlignCenter
                text: "Количество правильных ответов: " + qa_model.trueAnswers_
                color: "black"
                font.pixelSize: 16
            }
        }
    }
}
