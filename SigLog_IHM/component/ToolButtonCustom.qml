import QtQuick 2.4
import QtQuick.Controls 1.4

ToolButton
{
    Image {
        source: parent.iconSource
        fillMode: Image.PreserveAspectFit // For not stretching image (optional)
        anchors.fill: parent
        anchors.margins: 2 // Leaving space between image and borders (optional)
        anchors.bottomMargin:10 // Leaving space for text in bottom
    }
    Text {
        text: parent.text

        anchors.bottom: parent.bottom // Placing text in bottom
        anchors.margins: 2 // Leaving space between text and borders  (optional)
        anchors.horizontalCenter: parent.horizontalCenter // Centering text
        renderType: Text.NativeRendering // Rendering type (optional)
    }
}
