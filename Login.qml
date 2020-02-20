import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12
import Auth 1.0

Page {
    anchors.fill: parent

    ColumnLayout {
        width: parent.width
        spacing: 5

        Rectangle {
            height: 100
            opacity: 0
        }

        Text {
            id: log_text
            Layout.alignment: Qt.AlignHCenter
            text: "EXAMINATOR"
            font.pixelSize: 36
            font.bold: true
            color: "#FFFFFF"
            opacity: 0.15
            font.family: "Oswald"

            OpacityAnimator {
                target: log_text
                from: 0
                to: 1
                duration: 5000
                running: true
                loops: Animation.Infinite
            }

            ScaleAnimator {
                target: log_text
                from: 0.5
                to: 1
                duration: 5000
                running: true
            }
        }

        RowLayout {
            spacing: 15
            Layout.alignment: Qt.AlignHCenter

            Rectangle {
                id: anim_rect
                width: 40
                height: 40
                Layout.alignment: Qt.AlignCenter
                color: "#FFFFFF"
                opacity: 0.65

                Text {
                    text: "A"
                    font.family: "Oswald"
                    font.bold: true
                    anchors.centerIn: parent
                }

                RotationAnimator on rotation {
                    target: anim_rect
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    duration: 2000
                }
            }

            Rectangle {
                id: anim_rect2
                width: 40
                height: 40
                Layout.alignment: Qt.AlignCenter
                color: "#FFFFFF"
                opacity: 0.65
                Text {
                    text: "B"
                    font.family: "Oswald"
                    font.bold: true
                    anchors.centerIn: parent
                }

                RotationAnimator on rotation {
                    target: anim_rect2
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    duration: 2000
                }
            }

            Rectangle {
                id: anim_rect3
                width: 40
                height: 40
                Layout.alignment: Qt.AlignCenter
                color: "#FFFFFF"
                opacity: 0.65
                Text {
                    text: "C"
                    font.family: "Oswald"
                    font.bold: true
                    anchors.centerIn: parent
                }

                RotationAnimator on rotation {
                    target: anim_rect3
                    from: 0
                    to: 360
                    loops: Animation.Infinite
                    duration: 2000
                }
            }
        }

        Rectangle {
            height: 100
            opacity: 0
        }

        TextField {
            id: login_
            Layout.alignment: Qt.AlignHCenter
            width: 300
            placeholderText: "Введите логин"
        }

        TextField {
            id: password_
            Layout.alignment: Qt.AlignHCenter
            width: 300
            placeholderText: "Введите пароль"
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Войти"
            enabled: login_.text.length > 0 && password_.text.length > 0
            onClicked: {
                auth.enter(login_.text, password_.text)
            }
        }

        Label {
            text: auth.authFlag
            font.pixelSize: 20
            color: "red"
        }
    }
}
