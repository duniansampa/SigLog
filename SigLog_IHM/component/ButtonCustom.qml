import QtQuick 2.4

import "qrc:/common/common"

Rectangle{

    id: button
    width: 72
    height: 82
    border.width: 0
    state: "NORMAL"

    property alias name: blackText.text
    property alias source: blackImage.source
    property alias textVisible: blackText.visible
    property Component comp;

    signal clicked(string name, string state, Component comp)

    function stateChange(){
      if (button.state ===  "CLICKED"){
          button.state =  "NORMAL"
      }
      //console.log("statusChange");
    }

    Image {
        id: blackImage
        anchors.fill: button
        scale: 0.6
    }
    Text{
       id: blackText
       x: 0
       y: blackImage.x + blackImage.width
       width: button.width
       height: 36
       color: "#ffffff"
       anchors.horizontalCenterOffset: 0
       anchors.horizontalCenter: parent.horizontalCenter
       anchors.bottom: parent.bottom
       anchors.bottomMargin: 8
       horizontalAlignment: Text.AlignHCenter
       verticalAlignment: Text.AlignBottom
       font.pointSize: 8
    }

    MouseArea {
        id: mouseArea
        anchors.bottomMargin: 0
        anchors.fill: button
        z: 30
        onClicked: {
            button.clicked(name, button.state, button.comp);
            if (button.state == "ENTERED"){
                button.state = "CLICKED"
            }
        }
        hoverEnabled: true
        onPressed:{

        }
        onEntered:{
            if (button.state == "NORMAL"){
               button.state = "ENTERED"
            }
        }
        onExited:{
            if (button.state == "ENTERED"){
               button.state = "NORMAL"
            }
        }
    }
    states: [
        State {
            name: "NORMAL"

            PropertyChanges {
                target: button
                color: "#4F4F4F"
            }
        },
        State {
            name: "ENTERED"

            PropertyChanges {
                target: button
                color: "#696969"
            }
        },
        State {
            name: "CLICKED"
            PropertyChanges {
                target: button
                color: "#CFCFCF"
            }
        }
    ]
}
