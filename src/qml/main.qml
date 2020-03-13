import QtQuick 2.14
import QtQuick.Controls 2.14
import Auth 1.0
import Theory 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: "Examinator"

    Auth {
        id: auth

        onAuthFlagChanged: {
            if(authFlag === true) {
                stackView.push("qrc:/base")
            } else {
                stackView.pop()
            }
        }
    }

    TheoryData {
        id: theory_data
        txt: ""
        txt_name: ""
    }

    StackView {
        id: stackView
        initialItem: "qrc:/Login"
        anchors.fill: parent
    }
}
