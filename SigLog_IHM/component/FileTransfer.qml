import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import "qrc:/common/common"

import "qrc:/javaScript/javaScript/MyScript.js" as MyScript

import myCLibs 1.0

Background{

    id: fileTransfer

    property alias gridLayout: gridLayout1

    SplitView{
        id: splitView1
        anchors.fill: parent
        orientation: Qt.Vertical
        anchors.rightMargin: 16
        anchors.leftMargin: 16
        anchors.topMargin: 16
        anchors.bottomMargin: 16

        GridLayout {
            id: gridLayout1
            Layout.alignment: Qt.AlignTop
            anchors.topMargin: 24
            columnSpacing: 8
            rowSpacing: 8
            rows: 10
            columns: 8
            enabled: true
            //Layout.preferredHeight: fileTransfer.width/2

            Label {
                id: label2
                text: qsTr("Local Computer")
                Layout.columnSpan: 4
                Layout.bottomMargin: 8
            }

            Label {
                id: label1
                text: qsTr("Remote Computer")
                Layout.columnSpan: 4
                Layout.bottomMargin: 8
            }

            Label {
                id: label3
                text: qsTr("Adress")
                Layout.columnSpan: 1
            }

            ComboBox {
                id: comboBox1
                Layout.minimumWidth: 140
                Layout.columnSpan: 3
                Layout.fillWidth: true               
                model:["File","System" ]
            }

            Label {
                id: label4
                text: qsTr("Adress")
                Layout.columnSpan: 1
            }

            ComboBox {
                id: comboBox2
                Layout.minimumWidth: 140
                Layout.columnSpan: 3
                Layout.fillWidth: true
                model:["File","System" ]
            }

            ToolButton {
                id: toolButton1
                Layout.minimumWidth: 140
                Layout.columnSpan: 4
                Layout.fillWidth: true
            }

            ToolButton {
                id: toolButton2
                Layout.minimumWidth: 140
                Layout.columnSpan: 4
                Layout.fillWidth: true
            }

            TreeViewCustom {
                id: localFileSystem
                model: fsModelLocal
                iconRole: FileSystemModel.FileIconRole

                Layout.minimumWidth: 140
                Layout.preferredHeight: 310
                Layout.minimumHeight: 200
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 4
                Layout.rowSpan: 3

                Component.onCompleted:{
                    MyScript.createTableColumn(localFileSystem, "Name", "fileName", 200);
                    MyScript.createTableColumn(localFileSystem, "Size", "fileSize", 80);
                    MyScript.createTableColumn(localFileSystem, "Type", "fileType", 80);
                    MyScript.createTableColumn(localFileSystem, "Modified", "fileModified", 200);
                }
            }
            TreeViewCustom{
                id: remoteFileSystem
                model: fsModelRemote
                iconRole: FileSystemModel.FileIconRole

                Layout.minimumWidth: 140
                Layout.preferredHeight: 310
                Layout.minimumHeight: 200
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 4
                Layout.rowSpan: 3
                Component.onCompleted:{
                    MyScript.createTableColumn(remoteFileSystem, "Name", "fileName", 200);
                    MyScript.createTableColumn(remoteFileSystem, "Size", "fileSize", 80);
                    MyScript.createTableColumn(remoteFileSystem, "Type", "fileType", 80);
                    MyScript.createTableColumn(remoteFileSystem, "Modified", "fileModified", 200);
                }
            }
            Label {
                id: label5
                text: qsTr("0 object(s) selected")
                Layout.columnSpan: 4
            }
            Label {
                id: label6
                text: qsTr("0 object(s) selected")
                Layout.columnSpan: 4
            }
        }
        ColumnLayout {
            id: coolumHistoryClear

            Item{
                Layout.fillWidth: true
                Layout.minimumHeight: 8
            }

            Label {
                id: label7
                //anchors.top: parent.top
                text: qsTr("File Transfer event log")             
                Layout.fillWidth: true

            }
            TextArea{
                id: history
                Layout.preferredHeight: 50
                Layout.minimumHeight: 50
                Layout.fillWidth: true
                Layout.fillHeight:true

            }
        }
    }
    Component.onCompleted: {
       // console.log("---> " + fileTransfer.height);
    }

}
