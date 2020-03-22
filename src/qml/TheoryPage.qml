import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.12

Page {
    id: theory_page_info

    property bool save_visible: false
    property bool _visible: theory.thVisible

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

        Label {
            anchors.centerIn: parent
            text: theory.thName
        }

        ToolButton {
            id: edit_btn
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            visible: auth.userRole === 2

            Text {
                text: "EDIT"
                font.pixelSize: 16
                anchors.centerIn: parent
            }

            onClicked: {
                save_visible = true
                text_area.visible = false
                text_area.enabled = false

                text_edit.visible = true
                text_edit.enabled = true

                checkbox.visible = true
            }
        }

        ToolButton {
            anchors.right: parent.right
            anchors.rightMargin: 80
            anchors.verticalCenter: parent.verticalCenter
            visible: auth.userRole === 2 && save_visible === true

            Text {
                text: "SAVE"
                font.pixelSize: 16
                anchors.centerIn: parent
            }

            onClicked: {
                save_visible = false
                checkbox.visible = false
                theory.thVisible = checkbox.checked
                theory.thTheory = text_edit.text

                theory.saveChanged()
            }
        }

        CheckBox {
            id: checkbox
            anchors.right: parent.right
            anchors.rightMargin: 140
            anchors.verticalCenter: parent.verticalCenter
            visible: false
            checked: _visible

            Text {
                text: "VISIBLE"
                font.pixelSize: 16
                anchors.right: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    ScrollView {
        anchors.fill: parent

        Text {
            id: text_area
            padding: 25
            text: theory.thTheory
            color: "#ffffff"
        }

        TextEdit {
            id: text_edit
            padding: 25
            text: theory.thTheory
            color: "#ffffff"
            visible: false
            enabled: false
        }
    }
}
