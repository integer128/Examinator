import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {
    id: main_menu

    Menu {
        id: menuTB
        height: parent.height
        width: parent.width / 3

        MenuItem {
            text: "Панель управления"
            onClicked: {

            }
        }

        MenuItem {
            text: "Выход из аккаунта"
            onClicked: {

            }
        }

        MenuItem {
            text: "Выход"
            onClicked: {

            }
        }
    }

    header: ToolBar {
        height: 40

        ToolButton {

            Rectangle {
                width: 15
                height: 15
                color: "black"
                anchors.centerIn: parent
                radius: 22
            }

            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter

            onClicked: {
                menuTB.open()
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
                text: "Теория"
                font.family: "Oswald"
                font.italic: true
                font.pixelSize: 18
                anchors.centerIn: parent
            }

            Button {
                id: btn_1
                width: 200
                height: 50
                text: "Начать"
                anchors.bottom: parent.bottom

                background: Rectangle {
                    id: bg_rect
                    anchors.fill: parent
                    color: "#FFFFFF"
                    opacity: 0.65
                }

                onHoveredChanged: hovered ? rect_1.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rect_1.color = Qt.rgba(255, 255, 255, 0.65)
            }
        }

        Rectangle {
            id: rect_2
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "Проверь себя"
                font.family: "Oswald"
                font.italic: true
                font.pixelSize: 18
                anchors.centerIn: parent
            }

            Button {
                width: 200
                height: 50
                text: "Начать"
                anchors.bottom: parent.bottom

                background: Rectangle {
                    anchors.fill: parent
                    color: "#FFFFFF"
                    opacity: 0.65
                }

                onHoveredChanged: hovered ? rect_2.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rect_2.color = Qt.rgba(255, 255, 255, 0.65)
            }
        }

        Rectangle {
            id: rect_3
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "В разработке"
                font.family: "Oswald"
                font.italic: true
                font.pixelSize: 18
                anchors.centerIn: parent
            }

            Button {
                width: 200
                height: 50
                text: "Начать"
                anchors.bottom: parent.bottom

                background: Rectangle {
                    anchors.fill: parent
                    color: "#FFFFFF"
                    opacity: 0.65
                }

                onHoveredChanged: hovered ? rect_3.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rect_3.color = Qt.rgba(255, 255, 255, 0.65)
            }
        }
    }
}
