import QtQuick 2.5
import OpenGLUnderQML 1.0

Rectangle {
//    property alias mouseArea: mouseArea
//    property alias textEdit: textEdit

    width: 360
    height: 360

//    MouseArea {
//        id: mouseArea
//        anchors.fill: parent
//    }

//    TextEdit {
//        id: textEdit
//        text: qsTr("Enter some text...")
//        verticalAlignment: Text.AlignVCenter
//        anchors.top: parent.top
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.topMargin: 20
//        Rectangle {
//            anchors.fill: parent
//            anchors.margins: -10
//            color: "transparent"
//            border.width: 1
//        }
//    }

    Squircle {
        SequentialAnimation on t {
            NumberAnimation { to: 1; duration: 2500; easing.type: Easing.InQuad }
            NumberAnimation { to: 0; duration: 2500; easing.type: Easing.OutQuad }
            loops: Animation.Infinite
            running: true
        }
    }

    Rectangle {
        color: Qt.rgba(1, 1, 1, 0.7)
        radius: 10
        border.width: 1
        border.color: "white"
        anchors.fill: label
        anchors.margins: -10
    }

    Text {
        id: label
        color: "black"
        wrapMode: Text.WordWrap
        text: "The background here is a squircle rendered with raw OpenGL using the 'beforeRender()' signal in QQuickWindow. This text label and its border is rendered using QML"
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 20
    }
}
