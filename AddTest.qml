import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {

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
        anchors.fill: parent
        anchors.leftMargin: 25

        RowLayout {

            Label {
                text: "ВОПРОС:"
            }

            TextField {
                id: txtquestion
                placeholderText: "Введите вопрос"
            }
        }

        RowLayout {

            Label {
                text: "ОТВЕТ 1:"
            }

            TextField {
                id: answ1
                placeholderText: "Введите ответ 1"
            }
        }

        RowLayout {

            Label {
                text: "ОТВЕТ 2:"
            }

            TextField {
                id: answ2
                placeholderText: "Введите ответ 2"
            }
        }
        RowLayout {

            Label {
                text: "ОТВЕТ 3:"
            }

            TextField {
                id: answ3
                placeholderText: "Введите ответ 3"
            }
        }

        RowLayout {

            Label {
                text: "ВЕРНЫЙ ОТВЕТ:"
            }

            TextField {
                id: answt
                placeholderText: "Введите верный ответ"
            }
        }

        RowLayout {

            Label {
                text: "БАЛЛЫ:"
            }

            TextField {
                id: answb
                placeholderText: "Введите баллы за вопрос"
            }
        }

        Button {
            id: button1024
            text: "Добавить"
            enabled: answ1.text === answt.text ||
                     answ2.text === answt.text ||
                     answ3.text === answt.text

            onClicked:  {
                auth.addTest(txtquestion.text, answ1.text,
                            answ2.text, answ3.text,
                             answt.text, answb.text )
                stackView.pop()
            }
        }
    }
}
