import QtQuick 2.4

import "qrc:/common/common"

Rectangle{
    id: painelLateral
    width: 72
    color: "#4F4F4F"
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 0
    anchors.top: parent.top
    anchors.topMargin: 45
    focus: true
    ListView {
        id: plListView
        anchors.fill: parent
        clip: true
        property var lastItem
        model: ListModel {
            id: plListModel
            ListElement { imagePath: "qrc:/image/image/cloudy.png"; imageName:"Dashboard" }
            ListElement { imagePath: "qrc:/image/image/cloudy.png"; imageName:"MIB" }
            ListElement { imagePath: "qrc:/image/image/cloudy.png"; imageName:"Configuration" }
        }
        delegate: BlackButton {
            id: pldelegate
            width: plListView.width
        }



        Component.onCompleted:{
        }
    }
}

