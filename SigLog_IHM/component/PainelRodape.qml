import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

import "qrc:/common/common"

ToolBar {

    style: ToolBarStyle {

        background: Rectangle {
            //border.color: "#999"
            gradient: Gradient {
                GradientStop { position: 0 ; color: "#221010" }
                GradientStop { position: 1 ; color: "#221919" }
            }
        }
    }

    RowLayout {
        anchors.fill: parent
        ToolButton {

            //iconSource: "new.png"
        }
        ToolButton {
           // iconSource: "open.png"
        }
        ToolButton {

        }
    }
}
