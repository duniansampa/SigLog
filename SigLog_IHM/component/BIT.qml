import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

import "qrc:/common/common"

import "qrc:/javaScript/javaScript/MyScript.js" as MyScript

import myCLibs 1.0

Background{

    id: background
    property alias  timeLine: timeLine
    property alias  pathWiew: pathWiew
    property alias  pathModel: pathModel

    property real pathX0: pathWiew.width - 16
    property real pathX1: 16
    property real pathY: pathWiew.height/2

    GridLayout{
        id: gridLayout1
        anchors.fill: parent
        anchors.topMargin: 16
        anchors.leftMargin: 16
        anchors.rightMargin: 16
        anchors.bottomMargin: 16
        columnSpacing: 8
        rowSpacing: 8
        rows: 8
        columns: 8
        enabled: true



        Rectangle{
            id: timeLine
            width: parent.width
            height: 36
            color: "black"
            Layout.alignment: Qt.AlignTop
            Layout.minimumWidth: 140
            Layout.columnSpan: 8
            Layout.rowSpan: 1
            Layout.fillWidth: true

            Rectangle {

                anchors.centerIn: parent
                height: 1
                width: pathX0;
                color: "#9B9B9B"
            }


            RowLayout{
                spacing: 2
                anchors.fill: parent
                anchors.leftMargin: 8
                anchors.rightMargin: 8
                Button {
                    text: "Filter"
                    Layout.preferredWidth: 50
                    Layout.preferredHeight: 20

                    z: 100
                    onClicked:{
                    }

                    style: ButtonStyle {
                        background: Rectangle {
                            border.width: control.activeFocus ? 2 : 1
                            border.color: "#888"
                            //radius: 4
                            gradient: Gradient {
                                GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                                GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                            }
                        }
                    }
                }

                PathView {
                    id: pathWiew
                    Layout.minimumWidth: 100
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    interactive: false
                    z: 99

                    model: ListModel {
                        id: pathModel
                    }

                    delegate:  Rectangle {
                        id: delegate
                        //property int idx: 1
                        width: 14
                        height: 14
                        radius: 7
                        border.color: (pathWiew.count - idx) > 4 ? timeLine.color: "#9B9B9B"
                        color: (pathWiew.count - idx) > 4 ? "#9B9B9B" : timeLine.color
                        border.width: 3

                        Component.onCompleted:{
                            //console.log("idx: " + idx + " count: " + pathWiew.count );
                        }
                    }

                    path: Path {
                        startX: pathX0 ; startY: pathY
                        PathAttribute { name: "iconScale"; value: 1 }
                        PathAttribute { name: "iconOpacity"; value: 1.0 }

                        PathLine  { x: pathX1; y: pathY; }
                        PathAttribute { name: "iconScale"; value: 1}
                        PathAttribute { name: "iconOpacity"; value: 1 }
                    }
                }

                Button {
                    text: "Sync"
                    Layout.preferredWidth: 50
                    Layout.preferredHeight: 20
                    z: 100
                    onClicked:{
                        pathModel.insert(0, {"name": "Jane Doe", "idx": pathModel.count + 1})
                        console.log("maximumFlickVelocity  : " + pathWiew.maximumFlickVelocity  )
                    }

                    style: ButtonStyle {
                        background: Rectangle {
                            border.width: control.activeFocus ? 2 : 1
                            border.color: "#888"
                            gradient: Gradient {
                                GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                                GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                            }
                        }
                    }
                }
            }
        }

        TreeViewCustom{
            id: bitAnalyser
            Layout.minimumWidth: 140
            Layout.minimumHeight: 200
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.columnSpan: 8
            Layout.rowSpan: 7

            //model: TreeModel {
            //}


            Component.onCompleted: {
                //MyScript.createTableColumn(bitAnalyser, "Name", "name_role", 200)
                //MyScript.createTableColumn(bitAnalyser, "Name", "name_role", 200)
            }

        }

    }
}
