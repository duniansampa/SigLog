import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtBluetooth 5.5
import QtCanvas3D 1.0
import QtPositioning 5.5
import QtQuick.Extras 1.4
import QtQuick.XmlListModel 2.0
import QtSensors 5.5
import QtQuick.LocalStorage 2.0
import QtLocation 5.5
import QtTest 1.1
//import QtWebKit 3.0
import QtWebSockets 1.0
import QtNfc 5.5
import QtMultimedia 5.5
import QtWebChannel 1.0
import QtQuick.Layouts 1.2
import Enginio 1.0
import QtQuick.Controls.Styles 1.4


import "qrc:/common/common"
import "qrc:/component/component"

import "common"
import "component"

ApplicationWindow {
    id: applicationWindow1
    title: qsTr("MICAA")
    width: 900
    height: 600
    minimumWidth: 900
    minimumHeight: 600
    opacity: 1
    visible: true

    StackView {
        id: stackView
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 25
        anchors.top: painelTopo.bottom
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 1
        anchors.left: painelLateral.right
        anchors.leftMargin: 0
        enabled: true
        z: 8
        scale: 1
        transformOrigin: Item.Center
        initialItem: painelLateral.dashboard

        delegate: StackViewDelegate {
                function transitionFinished(properties)
                {
                    //properties.exitItem.opacity = 1
                }

                pushTransition: StackViewTransition {
                    PropertyAnimation {
                        target: enterItem
                        property: "opacity"

                    }
                    PropertyAnimation {
                        target: exitItem
                        property: "opacity"

                    }
                }
        }
    }
    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    PainelTopo{
        id: painelTopo
        height: 55
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.right: parent.right
        z: 6
    }

    PainelLateralCustom{
        id: painelLateral
        width: 82
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: painelTopo.bottom
        anchors.topMargin: 0
        z: 5
    }

    PainelRodape {
        id: painelRodape1
        x: 78
        y: 478
        width: 552
        height: 25
        anchors.left: painelLateral.right
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.right: parent.right
        visible: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        clip: false
        z: 7
    }
}
