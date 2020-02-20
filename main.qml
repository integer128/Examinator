import QtQuick 2.14
import QtQuick.Controls 2.14
import Auth 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: "Examinator"

    Auth {
        id: auth
    }

    StackView {
        id: stackView
        initialItem: "Login.qml"
        anchors.fill: parent
    }
}
