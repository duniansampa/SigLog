
function createImageIcon(objParent, fullPath) {

    var imageString = 'import QtQuick 2.4; '
       + 'Image { '
       +     'id: imageIcon; '
       +     'source: "image://provider/' + fullPath + '"; '
       +     'width: 16; '
       +     'height: 16; '
       +     'anchors.verticalCenter: parent.verticalCenter; '
       + '}'

    var img = Qt.createQmlObject(imageString, objParent)

    if(img === null){
        console.log("Error creating new imageIcon!")
        return undefined;
    }
    return img
}
function createText(objParent, data) {

    var txt;
    var textString = 'import QtQuick 2.4; '
        + 'Text { '
        +   'color: "' + data.textColor + '"; '
        +   'text: "' + data.value + '"; '
        +   'verticalAlignment: Text.AlignVCenter; '
        +   'anchors.verticalCenter: parent.verticalCenter; '
        + '}'
    //console.log("textString: " + textString)

    txt = Qt.createQmlObject(textString, objParent)

    if(txt === null){
        console.log("Error creating new text!")
        return undefined;
    }
    return txt
}

function createTableColumn(objParent, name, role, width) {

    var column;
    var columnString = 'import QtQuick.Controls 1.4; '
           + 'TableViewColumn { '
           +    'title: qsTr("' + name + '"); '
           +    'role: "' + role +'"; '
           +    'width: ' + width + '; '
           +    'resizable: true; '
           + '}'

    //console.log("columnString: " + columnString)
    column = Qt.createQmlObject(columnString, objParent)

    if(column === null){
        console.log("Error creating new TableViewColumn!")
        return undefined;
    }
    objParent.addColumn(column)
    return column
}

