import QtQuick 2.4

import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

import "qrc:/common/common/"

Item {
    id: content

    anchors.top: parent.top
    //anchors.left: parent.left
    anchors.right: parent.right
    clip: false
    opacity: 1

    //Operations...
    property alias get: get
    property alias getNext: getNext
    property alias getBulk: getBulk
    property alias snmpWalk: snmpWalk
    property alias set: set

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
            id: syntax
            Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }
        Label {
            id: label2
            text: qsTr("Status")
            Layout.columnSpan: 1
        }
        TextField {
            id: status
            Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }

        Label {
            id: label3
            text: qsTr("Access")
            Layout.columnSpan: 1
        }
        TextField {
            id: access
            Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }
        Label {
            id: label4
            text: qsTr("Reference")
            Layout.columnSpan: 1
        }
        TextField {
            id: reference
            Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 3
        }
        Label {
            id: label5
            text: qsTr("Index")
            Layout.columnSpan: 1
        }
        TextField {
            id: index
            Layout.minimumWidth: 140
            Layout.fillWidth: true
            Layout.columnSpan: 7
        }
        Label {
            id: label6
            text: qsTr("Object ID")
            Layout.columnSpan: 1
        }
        TextField {
            id: objectID
            Layout.minimumWidth: 140
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
            id: description

            Layout.minimumWidth: 140
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
        anchors.topMargin: 12
        anchors.right: parent.right
        anchors.rightMargin: 12
        //anchors.left: parent.left
        anchors.top: gridLayout.bottom

        Button {
            id: get
            text: qsTr("Get")
            enabled: false
        }
        Button {
            id: getNext
            text: qsTr("Next")
            enabled: false
        }
        Button {
            id: getBulk
            text: qsTr("Bulk")
            enabled: false
        }
        Button {
            id: snmpWalk
            text: qsTr("Walk")
            enabled: false
        }
        Button {
            id: set
            text: qsTr("Set")
            enabled: false
        }
    }
    TextArea{
        id: history
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
        anchors.rightMargin: 8
        anchors.bottomMargin: 8
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Button {
            id: clear
            text: qsTr("Save")
            enabled: false
        }
        Button {
            id: save
            text: qsTr("Clear")
            enabled: false
        }
    }


}


