import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

import "qrc:/common/common"

Rectangle {

    id: toolbar
    height: 20
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.right: parent.right
    anchors.rightMargin: 0
    anchors.top: parent.top
    anchors.topMargin: 0
    gradient: Gradient {
       GradientStop { position: 0 ; color: "#221919" }
       GradientStop { position: 1 ; color: "#221919" }
    }

    Button {
        x: 16
        y: 10
        anchors.verticalCenter: parent.verticalCenter
        property bool clickedState: false

        style: ButtonStyle {

            background: Rectangle {
                id: backg
                color: control.clickedState ?  "cadetblue" : "transparent"
                implicitWidth: 24
                implicitHeight: 24
                radius: 4
                Image {
                    anchors.fill: parent
                    source: "qrc:/image/image/More-32.png"
                }
            }

        }
        onClicked: {
            clickedState = !clickedState;
        }
    }
}
