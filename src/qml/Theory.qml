import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {
    id: theory_page

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

    RowLayout {
        anchors.fill: parent

        Rectangle {
            id: rect_1
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "Глава 1"
                font.italic: true
                font.pixelSize: 18
                anchors.centerIn: parent
            }

            Label {
                id: label_1
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                color: "red"
                font.bold: true
            }

            Button {
                id: btn_1
                width: 200
                height: 50
                text: "Читать"
                anchors.bottom: parent.bottom

                background: Rectangle {
                    id: bg_rect
                    anchors.fill: parent
                    color: "#FFFFFF"
                    opacity: 0.65
                }

                onHoveredChanged: hovered ? rect_1.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rect_1.color = Qt.rgba(255, 255, 255, 0.65)
                onClicked: {
                    theory.updateTheory(1)
                    if(theory.thVisible === true || auth.userRole === 2) {
                        stackView.push("qrc:/TheoryPage")
                    } else {
                        label_1.text = "Данный раздел закрыт!"
                        enabled = false
                    }
                }
            }
        }

        Rectangle {
            id: rect_2
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "Глава 2"
                font.italic: true
                font.pixelSize: 18
                anchors.centerIn: parent
            }

            Label {
                id: label_2
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                color: "red"
                font.bold: true
            }

            Button {
                width: 200
                height: 50
                text: "Читать"
                anchors.bottom: parent.bottom

                background: Rectangle {
                    anchors.fill: parent
                    color: "#FFFFFF"
                    opacity: 0.65
                }

                onHoveredChanged: hovered ? rect_2.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rect_2.color = Qt.rgba(255, 255, 255, 0.65)

                onClicked: {
                    theory.updateTheory(2)
                    if(theory.thVisible === true || auth.userRole === 2) {
                        stackView.push("qrc:/TheoryPage")
                    }else {
                        label_2.text = "Данный раздел закрыт!"
                        enabled = false
                    }
                }
            }
        }

        Rectangle {
            id: rect_3
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "Глава 3"
                font.italic: true
                font.pixelSize: 18
                anchors.centerIn: parent
            }

            Label {
                id: label_3
                anchors.top: parent.top
                color: "red"
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                width: 200
                height: 50
                text: "Читать"
                anchors.bottom: parent.bottom

                background: Rectangle {
                    anchors.fill: parent
                    color: "#FFFFFF"
                    opacity: 0.65
                }

                onHoveredChanged: hovered ? rect_3.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rect_3.color = Qt.rgba(255, 255, 255, 0.65)
                onClicked: {
                    theory.updateTheory(3)
                    if(theory.thVisible === true || auth.userRole === 2) {
                        stackView.push("qrc:/TheoryPage")
                    } else {
                        label_3.text = "Данный раздел закрыт!"
                        enabled = false
                    }
                }
            }
        }
    }
}
