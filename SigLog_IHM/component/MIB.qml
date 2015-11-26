import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import "qrc:/common/common"

import "qrc:/javaScript/javaScript/MyScript.js" as MyScript

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

            TreeViewCustom {
                id: mibTreeView
                iconRole: Qt.DecorationRole
                width: parent.width
                height: parent.height - toolBar.height
                model: MibTreeModel{
                   id: mibTreeModel
                }

                onClicked:{
                    //index
                    logger.log("Clicked");

                    mibObj.tfAccess.text = mibTreeModel.data(index, MibTreeModel.MibAcessRole);
                    mibObj.tfStatus.text = mibTreeModel.data(index, MibTreeModel.MibStatusRole);
                    //mibTreeModel.data(index, MibTreeModel.MibIn);
                    mibObj.tfSyntax.text = mibTreeModel.data(index, MibTreeModel.MibTypeRole);
                    mibObj.tfObjectID.text = mibTreeModel.data(index, MibTreeModel.MibOidRole);
                    mibObj.tfReference.text = mibTreeModel.data(index, MibTreeModel.MibReferenceRole);
                    mibObj.taDescription.text = mibTreeModel.data(index, MibTreeModel.MibDescriptionRole);


                }

                Component.onCompleted:{
                   // console.log("------>");
                    mibTreeModel.loadMibToThree("/usr/share/snmp/mibs/NET-SNMP-EXAMPLES-MIB.txt");
                    MyScript.createTableColumn(mibTreeView, "Módulos Carregados", "mibLabel", 5000);

                }
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
