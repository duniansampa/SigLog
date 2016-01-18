import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4


import "qrc:/common/common"

import "qrc:/javaScript/javaScript/MyScript.js" as MyScript

import myCLibs 1.0

Background{
    id: mibPanel

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            var path = fileDialog.fileUrl.toString();
            // remove prefixed "file:///"
            path= path.replace(/^(file:\/{2})|(qrc:\/{2})|(http:\/{2})/,"");
            // unescape html codes like '%23' for '#'
            var cleanPath = decodeURIComponent(path);
            mibTreeModel.loadMibToThree(cleanPath);
            mibTreeView.expand( mibTreeModel.firstIndex);
        }
        onRejected: {
        }
    }

    SplitView {
        id: splitView1
        anchors.fill: parent
        orientation: Qt.Horizontal


        ColumnLayout{
            id: columnLayout
            spacing: 0

            Rectangle{
                color: "white"
                height: 20
                Layout.fillWidth: true
                Layout.maximumWidth: mibTreeView.maxWidthSize

                RowLayout{
                    anchors.fill: parent
                    Button{
                        style: ButtonStyle {

                            background: Rectangle {
                                id: backg
                                color: control.pressed ?  "cadetblue" : "transparent"
                                implicitWidth: 20
                                implicitHeight: 20
                                Image {
                                    anchors.fill: parent
                                    source:  "qrc:/image/image/Search-32.png"
                                }
                            }

                        }
                    }
                    TextInput{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }
            }

            TreeViewCustom {
                id: mibTreeView
                iconRole: Qt.DecorationRole
                headerVisible: false
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.minimumWidth: (mibPanel.width/4) > 250 ? 250 : (mibPanel.width/4)
                Layout.maximumWidth:  maxWidthSize
                property real maxWidthSize:  (2 * mibPanel.width)/3

                model: MibTreeModel{
                   id: mibTreeModel
                }

                onClicked:{
                    //index
                    logger.log("-------------------------")
                    logger.log("Index " + index  )
                    logger.log("Index " + mibTreeView.currentIndex )
                    mibObj.tfAccess.text = mibTreeModel.data(index, MibTreeModel.MibAcessRole);
                    mibObj.tfStatus.text = mibTreeModel.data(index, MibTreeModel.MibStatusRole);
                    //mibTreeModel.data(index, MibTreeModel.MibIn);
                    mibObj.tfSyntax.text = mibTreeModel.data(index, MibTreeModel.MibTypeRole);
                    mibObj.tfObjectID.text = mibTreeModel.data(index, MibTreeModel.MibOidRole);
                    mibObj.tfReference.text = mibTreeModel.data(index, MibTreeModel.MibReferenceRole);
                    mibObj.taDescription.text = mibTreeModel.data(index, MibTreeModel.MibDescriptionRole);

                }

                Component.onCompleted:{
                    MyScript.createTableColumn(mibTreeView, "Módulos Carregados", "mibLabel", 2000);

                }
            }

            ToolBar{
                id: toolBar
                //anchors.bottom: parent.bottom
                Layout.fillWidth: true
                Layout.maximumWidth: mibTreeView.maxWidthSize

                style: ToolBarStyle {

                    background: Rectangle {
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: "#221010" }
                            GradientStop { position: 1 ; color: "#221919" }
                        }
                    }
                }


                RowLayout{
                    anchors.fill:  parent
                    spacing: 2

                    Item { Layout.fillWidth: true }
                    ToolButton {
                        id: tbLoadMib
                        iconSource: "qrc:/image/image/Add File-32.png"
                        text: qsTr("Load MIB")
                        scale: 1
                        Layout.alignment: Qt.AlignHCenter
                        onClicked: {
                            fileDialog.open()
                        }
                    }
                    ToolButton {
                        id: tbUnloadMib
                        iconSource: "qrc:/image/image/Delete File-32.png"
                        text: qsTr("Unload MIB")
                        scale: 1
                        Layout.alignment: Qt.AlignHCenter
                        onClicked: {

                          var modulesLoaded = mibTreeModel.modulesLoaded;
                          var index = mibTreeView.currentIndex

                          logger.log("row: " + index.row);

                          logger.log("modulesLoaded.length: " + modulesLoaded.length )
                          if( modulesLoaded.length > 0) {
                              if(index === mibTreeModel.firstIndex){

                                   mibTreeModel.unloadMibToThree(index);
                                   return;
                              } else{

                                 logger.log("index.isValid: " + mibTreeModel.isIndexValid(index) )

                                  while(mibTreeModel.isIndexValid(index)){
                                    logger.log("length: " + modulesLoaded.length )
                                    for(var i = 0; i < modulesLoaded.length; i++){
                                        logger.log("---------------------")
                                        if(mibTreeModel.data(index, Qt.DisplayRole) === modulesLoaded[i] ){
                                            logger.log("index is found");
                                            mibTreeModel.unloadMibToThree(index);
                                            return;
                                        }
                                    }
                                    index = mibTreeModel.indexParent(index)
                                  }
                              }
                          }
                        }
                    }
                    ToolButton {
                        id: tbCollapse
                        iconSource: "qrc:/image/image/Collapse Filled-50.png"
                        text: qsTr("Collapse")
                        scale: 1
                        Layout.alignment: Qt.AlignHCenter


                        function collapseAll(index){

                            if(!mibTreeModel.isIndexValid(index))
                                return;

                            mibTreeView.collapse(index);

                            var rows = mibTreeModel.rowCount(index)

                            for(var i = 0; i < rows; i++){
                               var child = mibTreeModel.index(i, 0, index);

                               collapseAll(child);
                            }
                        }

                        onClicked: {
                            mibTreeView.clicked( mibTreeModel.firstIndex)

                            tbCollapse.collapseAll(mibTreeModel.firstIndex);
                        }
                    }

                    ToolButton {
                        id: tbExpand
                        iconSource: "qrc:/image/image/Expand Filled-50.png"
                        text: qsTr("Expand")
                        scale: 1
                        Layout.alignment: Qt.AlignHCenter

                        function expandAll(index){

                            if(!mibTreeModel.isIndexValid(index))
                                return;

                            mibTreeView.expand(index);

                            var rows = mibTreeModel.rowCount(index)

                            for(var i = 0; i < rows; i++){
                               var child = mibTreeModel.index(i, 0, index);
                               expandAll(child);
                            }
                        }
                        onClicked: {
                            mibTreeView.clicked( mibTreeModel.firstIndex)

                            tbExpand.expandAll(mibTreeModel.firstIndex);
                        }
                    }

                    ToolButton {
                        id: tbDescriptionMib
                        iconSource: "qrc:/image/image/Survey-32.png"
                        text: qsTr("Description")
                        scale: 1
                        Layout.alignment: Qt.AlignHCenter
                        onClicked: {

                            logger.log("Index " + mibTreeView.indexAt(0,1).row + "  " +mibTreeView.indexAt(0,1).collumn  )
                        }
                    }
                    Item { Layout.fillWidth: true }
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
