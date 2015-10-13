import QtQuick 2.4
import QtQuick.Controls 1.4

import "qrc:/common/common"

import myCLibs 1.0


Rectangle{
    id: box

    property alias model: thisTreeView.model

    TreeView {
        id: thisTreeView
        anchors.fill: parent
        //backgroundVisible: false
        alternatingRowColors: false
        //property int size: 32
        model: TreeModel {
            id: treeModel
        }
        headerDelegate: TextField{
            readOnly  : false
            placeholderText: qsTr("Search")

        }


        rowDelegate:Rectangle{
            id: rowDelegate
            color: "white"
        }
        itemDelegate: Rectangle{
               color: styleData.selected ? "lightsteelblue": "white"
               Row {
                  // Image {
                  //     id: image
                   //    scale: 0.5
                   //    source: styleData.hasChildren ? "qrc:/image/image/blue.png" : "qrc:/image/image/note.png"

                   //}
                   Text {
                       color: styleData.textColor
                       elide: styleData.elideMode
                       verticalAlignment: Text.AlignVCenter
                       text: styleData.value === undefined ? "" : styleData.value
                   }
               }
        }
        TableViewColumn {
            role: "name_role"
            title: "Name"
            width: treeView.width
        }

        onClicked:{
            //console.log("Box: clicked")
        }

        onDoubleClicked:{
            if(thisTreeView.isExpanded(index))
                thisTreeView.collapse(index);
            else{
                thisTreeView.expand(index)
            }
        }
    }

    Component.onCompleted:{
        thisTreeView.itemd
    }
}

