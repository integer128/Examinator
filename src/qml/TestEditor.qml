import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {
    id: editor_page
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

        Button {
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            flat: true
            width: 150

            Text {
                text: "ДОБАВИТЬ ВОПРОС"
                font.pixelSize: 16
                anchors.centerIn: parent
            }

            onClicked: {
                stackView.push("AddTest")
            }
        }
    }

    ColumnLayout {
        id: ccl
        anchors.fill: parent

        ListView {
            id: testEditorView
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 20
            model: teditor

            delegate: Pane {
                id: main_pain
                height: 60
                Material.elevation: 1
                width: editor_page.width

                ColumnLayout {
                    anchors.fill: parent

                    RowLayout {
                        spacing: 2
                        Layout.fillWidth: true

                        Label {
                            id: label112
                            text: "TESTNAME:" + testquestion
                            font.pixelSize: 18
                            Layout.alignment: Qt.AlignHCenter
                        }

                        TextField {
                            id: label112_change
                            visible: false
                            text: testquestion
                            Layout.alignment: Qt.AlignHCenter
                        }

                        MouseArea {
                            id: tedit_mousearea
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            onClicked: {
                                if(label_answer1.visible === false){
                                    main_pain.height = main_pain.height + 300
                                    label_answer1.visible = true
                                    label_answer2.visible = true
                                    label_answer3.visible = true
                                    label_answert.visible = true
                                    datasave_btn.visible = true
                                    label_points.visible = true
                                    label112.visible = false
                                    label112_change.visible = true
                                } else {
                                    main_pain.height = main_pain.height - 300
                                    label_answer1.visible = false
                                    label_answer2.visible = false
                                    label_answer3.visible = false
                                    label_answert.visible = false
                                    datasave_btn.visible = false
                                    label_points.visible = false
                                    label112_change.visible = false
                                    label112.visible = true
                                }
                            }
                        }
                    }

                    RowLayout {
                        Layout.alignment: Qt.AlignVCenter
                        id: label_answer1
                        spacing: 2
                        visible: false
                        Label {
                            text: "answer1:"
                        }

                        TextField {
                            id: label_answer1_changed
                            text: testanswer1
                        }
                    }

                    RowLayout {
                        Layout.alignment: Qt.AlignVCenter
                        id: label_answer2
                        spacing: 2
                        visible: false
                        Label {
                            text: "answer2:"
                        }

                        TextField {
                            id: label_answer2_changed
                            text: testanswer2
                        }
                    }

                    RowLayout {
                        Layout.alignment: Qt.AlignVCenter
                        id: label_answer3
                        spacing: 2
                        visible: false
                        Label {
                            text: "answer3:"
                        }

                        TextField {
                            id: label_answer3_changed
                            text:testanswer3
                        }
                    }

                    RowLayout {
                        Layout.alignment: Qt.AlignVCenter
                        id: label_answert
                        spacing: 2
                        visible: false
                        Label {
                            text: "true answer:"
                        }

                        TextField {
                            id: label_answert_changed
                            text: testtrueanswer
                        }
                    }

                    RowLayout {
                        Layout.alignment: Qt.AlignVCenter
                        id: label_points
                        spacing: 2
                        visible: false
                        Label {
                            text: "points:"
                        }

                        TextField {
                            id: label_points_changed
                            text: testpoint
                        }
                    }

                    Button {
                        id: datasave_btn
                        width: parent.width
                        height: 30
                        visible: false
                        text: "СОХРАНИТЬ"
                        enabled: label_answer1_changed.text === label_answert_changed.text ||
                                 label_answer2_changed.text === label_answert_changed.text ||
                                 label_answer3_changed.text === label_answert_changed.text
                        onClicked: {
                            teditor.saveChanges(testid, label112_change.text,
                                                label_answer1_changed.text,
                                                label_answer2_changed.text,
                                                label_answer3_changed.text,
                                                label_answert_changed.text,
                                                label_points_changed.text)

                        }
                    }
                }
            }
        }
    }
}
