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
                    stackView.push("qrc:/TheoryPage")
                    theory.updateTheory(1)
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
                    stackView.push("qrc:/TheoryPage")
                    theory.updateTheory(2)
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
                    stackView.push("qrc:/TheoryPage")
                    theory.updateTheory(3)
                }
            }
        }
    }
}
