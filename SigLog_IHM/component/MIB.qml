import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import "qrc:/common/common"

import myCLibs 1.0

Background{

    SplitView {
        id: splitView1
        anchors.fill: parent
        orientation: Qt.Horizontal

        Rectangle{
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            Layout.minimumWidth: 200
            Layout.preferredWidth: 200
            Layout.maximumWidth: parent.width/3
            TreeViewCustom{
                id: treeView
                width: parent.width
                height: parent.height - toolBar.height
            }
            ToolBar{
                id: toolBar
                anchors.bottom: parent.bottom
                RowLayout{
                    spacing: 2
                    ToolButton {
                        id: tbBa
                        iconSource: "qrc:/image/image/icon-back.png"
                        text: qsTr("B")
                        scale: 0.5
                        onClicked: {
                            console.log("onClicked");
                        }
                    }

                    ToolButton {
                        id: tbGo
                        iconSource: "qrc:/image/image/icon-go.png"
                        text: qsTr("F")
                        scale: 0.5
                        onClicked: {

                        }
                    }
                }
            }

        }
        MibObj{
          id: mibObj

        }
    }

    Component.onCompleted: {
        //treeView.currentModel.a
    }
}
