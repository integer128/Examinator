import QtQuick 2.14
import QtQuick.Controls 2.14
import User 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: "Examinator"

    User {
        id: auth

        onAuthFlagChanged: {
            if(authFlag === true) {
                stackView.push("qrc:/base")
            } else {
                stackView.pop()

            }
        }
    }

    StackView {
        id: stackView
        initialItem: "qrc:/Login"
        anchors.fill: parent
    }
}
