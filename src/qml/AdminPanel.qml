import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {
    id: adminPanel_page

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
        spacing: 5

        Button {
            width: 300
            height: 100
            Layout.alignment: Qt.AlignHCenter
            text: "Редактор тестов"

            onClicked: {

            }
        }

        Button {
            width: 300
            height: 100
            Layout.alignment: Qt.AlignHCenter
            text: "Результаты тестирования"

            onClicked: {
                stackView.push("TestResults")
            }
        }
    }
}
