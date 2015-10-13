import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2


import "qrc:/common/common"

import "qrc:/javaScript/javaScript/MyScript.js" as MyScript

import myCLibs 1.0

TreeView {
    id: treeView

    rowDelegate:Rectangle{
        id: rowDelegate
        color: "white"
        height: 19
    }
    itemDelegate: Rectangle{
           id: delegate
           color: styleData.selected ? "lightsteelblue": "white"

           Row {
                 id: itemRow
                 spacing: 4

                 property var img;
                 property var txt;
                 property var value: styleData.value
                 property var column: styleData.column
                 property var row: styleData.row
                 property var index: styleData.index
                 property var textColor: styleData.textColor
                 property var textAlignment: styleData.textAlignment

                 onValueChanged: {
                     if( itemRow.txt === undefined && row !== undefined && column !== undefined && value !== undefined && value !== ""){
                         if(column === 0){
                             var icon = treeView.model.data(index, FileSystemModel.FileIconRole)
                             if(icon !== undefined && icon !== null){
                                ipWrapper.icon = icon
                                itemRow.img = MyScript.createImageIcon(itemRow, value)
                             }
                         }
                         itemRow.txt = MyScript.createText(itemRow, styleData)
                       }

                 }
           }
    }

    onDoubleClicked:{
        if(treeView.isExpanded(index)){
            treeView.collapse(index);        
        }else{
            treeView.expand(index)
        }
    }
    onCollapsed:{
    }
    onExpanded:{
    }
}
