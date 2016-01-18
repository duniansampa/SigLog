import QtQuick 2.4

import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

import "qrc:/common/common/"

Item {
    id: content

    anchors.top: parent.top
    //anchors.left: parent.left
    anchors.right: parent.right
    clip: false
    opacity: 1

    //Operations...

    property alias btSave: btSave
    property alias btClear: btClear
    property alias taHistory: taHistory
    property alias taDescription: taDescription
    property alias tfObjectID: tfObjectID
    property alias tfIndex: tfIndex
    property alias tfReference: tfReference
    property alias tfAccess: tfAccess
    property alias tfStatus: tfStatus
    property alias tfSyntax: tfSyntax

    property alias btGet: btGet
    property alias btGetNext: btGetNext
    property alias btSnmpWalk: btSnmpWalk
    property alias btSet: btSet

    property alias gridLayout: gridLayout

    GridLayout {
        id: gridLayout

        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.rightMargin: 16
        anchors.leftMargin: 16
        anchors.topMargin: 16
        columnSpacing: 8
        rowSpacing: 1
        rows: 5
        columns: 8
        enabled: true

        Label {
            id: label1
            text: qsTr("Syntax")
            Layout.columnSpan: 1
        }
        TextField {
            id: tfSyntax
            readOnly: true
            //Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }
        Label {
            id: label2TextArea
            text: qsTr("Status")
            Layout.columnSpan: 1
        }
        TextField {
            id: tfStatus
            readOnly: true
            //Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }

        Label {
            id: label3
            text: qsTr("Access")
            Layout.columnSpan: 1
        }
        TextField {
            id: tfAccess
            readOnly: true
            //Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }
        Label {
            id: label4
            text: qsTr("Reference")
            Layout.columnSpan: 1
        }
        TextField {
            id: tfReference
            readOnly: true
            //Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }
        Label {
            id: label5
            text: qsTr("Index")
            Layout.columnSpan: 1
        }
        TextField {
            id: tfIndex
            readOnly: true
            //Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 7
        }
        Label {
            id: label6
            text: qsTr("Object ID")
            Layout.columnSpan: 1
        }
        TextField {
            id: tfObjectID
            readOnly: true
            //Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 7
        }

        Label {
            id: label7
            text: qsTr("Description")
            Layout.columnSpan: 1
            Layout.rowSpan: 1
        }

        TextArea {
            id: taDescription

            //Layout.minimumWidth: 140
            Layout.maximumHeight: 80
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.columnSpan: 7
            Layout.rowSpan: 1
           // ColorAnimation
        }
    }

    RowLayout {
        id: rowButton

        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: gridLayout.bottom

        anchors.topMargin: 12
        anchors.rightMargin: 12

        Label {
            id: label9
            Layout.fillWidth: true
        }

        Button {
            id: btGet
            //text: qsTr("Get")
            iconSource: "qrc:/image/image/Get-32.png"
            onClicked: {
                commands.get();
            }
        }
        Button {
            id: btGetNext
            //text: qsTr("GetNext")
            iconSource: "qrc:/image/image/Get Next-32.png"
            onClicked: {

            }

        }
        Button {
            id: btSnmpWalk
            //text: qsTr("SnmpWalk")
            iconName: "SNMP WALK"
            iconSource: "qrc:/image/image/Exercise-32.png"
        }
        Button {
            id: btSet
            //text: qsTr("Set")
            iconSource: "qrc:/image/image/Setting-32.png"
            onClicked: {

            }
        }
    }
    TextArea{
        id: taHistory
        anchors.top: rowButton.bottom
        anchors.bottom: rowSaveClear.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 16
        anchors.bottomMargin: 8
        anchors.leftMargin: 8
        anchors.topMargin: 8
        //height: 100
        //color: "white"
    }

    RowLayout {
        id: rowSaveClear
        anchors.topMargin: 8
        anchors.rightMargin: 12
        anchors.bottomMargin: 8
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Button {
            id: btClear
            //text: qsTr("Save")
            iconSource: "qrc:/image/image/Save Filled-32.png"
            enabled: true
        }
        Button {
            id: btSave
            //text: qsTr("Clear")
            iconSource: "qrc:/image/image/Broom-32.png"
            enabled: true
        }
    }


}


