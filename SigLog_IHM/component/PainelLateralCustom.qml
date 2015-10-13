import QtQuick 2.4

import "qrc:/common/common"

Rectangle{
    id: painel
    width: 72
    color: "#4F4F4F"
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 0
    anchors.top: parent.top
    anchors.topMargin: 45
    focus: true

    property alias dashboard: buttDashboard.comp
    property alias helf: buttHelf.comp
    property alias mib: buttMib.comp
    property alias bit: buttBit.comp
    property alias transfer: butTransfer.comp
    property alias config: butConfig.comp
    property var  listButton: [buttDashboard, buttHelf, buttMib, buttBit, butTransfer, butConfig ]

    function buttonPainelClicked(name, state, comp){
        if(state !== "CLICKED"){
            stackView.pop();
            stackView.push({item: comp});
            stackView.currentItem.forceActiveFocus();
        }
    }

    Column{
        anchors {
            top: parent.top
            left: parent.left
        }

        //spacing: 0

        ButtonCustom {

            id: buttDashboard
            width: painel.width
            source: "qrc:/image/image/cloudy.png";
            name: qsTr("Dashboard")
            state: "CLICKED"
            comp: Background{
                RedBox{}
            }
        }
        ButtonCustom {
            id: buttHelf
            width: painel.width
            source: "qrc:/image/image/cloudy.png"
            name: qsTr("Helf")
            comp: Background{
                 BlueBox{}
            }
        }
        ButtonCustom {
            id: buttMib
            width: painel.width
            source: "qrc:/image/image/cloudy.png"
            name: qsTr("Mib")
            comp: MIB{

            }
        }
        ButtonCustom {
            id: buttBit
            width: painel.width
            source: "qrc:/image/image/cloudy.png"
            name: qsTr("Bit")
            comp: BIT{

            }
        }

    }

    Column{
        anchors {
            bottom: parent.bottom
            left: parent.left
        }

        //spacing: 8


        ButtonCustom {
            id: butTransfer
            width: painel.width
            source: "qrc:/image/image/cloudy.png";
            name: qsTr("Transfer")
            textVisible: true
            comp: FileTransfer{
            }
        }
        ButtonCustom {
            id: butConfig
            width: painel.width
            source: "qrc:/image/image/cloudy.png";
            name: qsTr("Configuration")
            textVisible: false
            comp: Background{
                BlueBox{}
            }
        }
    }
    Component.onCompleted:{

        for( var i = 0; i < listButton.length; i++ ){
            for(var j = 0; j < listButton.length; j++){
                if(i != j){
                    listButton[i].clicked.connect(listButton[j].stateChange)
                }
            }
            listButton[i].clicked.connect(painel.buttonPainelClicked);
        }
    }

}
