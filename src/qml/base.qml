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
            enabled: auth.userRole === 2
            onClicked: {
                stackView.push("qrc:/AdminPanel")
            }
        }

        MenuItem {
            text: "Выход из аккаунта"
            onClicked: {
                stackView.pop()
                auth.authFlag = false
            }
        }

        MenuItem {
            text: "Выход"
            onClicked: {
                Qt.callLater(Qt.quit)
            }
        }
    }

    header: ToolBar {
        height: 40

        ToolButton {
            id: tbtn
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter

            Rectangle {
                width: 15
                height: 15
                color: "black"
                anchors.centerIn: parent
                radius: 22
            }

            onClicked: {
                menuTB.open()
            }
        }

        Label {
            id: fio_label
            x: tbtn.width + 10
            topPadding: 10
            text: "FIO"
        }
    }

    RowLayout {
        anchors.fill: parent

        Rectangle {
            id: rec1
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "Теория"
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

                onHoveredChanged: hovered ? rec1.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rec1.color = Qt.rgba(255, 255, 255, 0.65)
                onClicked: {
                    stackView.push("qrc:/Theory")
                }
            }
        }

        Rectangle {
            id: rec2
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "Проверь себя"
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

                onHoveredChanged: hovered ? rec2.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rec2.color = Qt.rgba(255, 255, 255, 0.65)
                onClicked: {
                    qa_model.updateData()
                    qa_model.createVariant()
                    stackView.push("qrc:/Test")
                }
            }
        }

        Rectangle {
            id: rec3
            height: 150
            width: 200
            Layout.alignment: Qt.AlignHCenter
            color: Qt.rgba(255, 255, 255, 0.65)

            Text {
                text: "В разработке"
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

                onHoveredChanged: hovered ? rec3.color = Qt.rgba(255, 255, 255, 0.35)
                                          : rec3.color = Qt.rgba(255, 255, 255, 0.65)
            }
        }
    }
}
