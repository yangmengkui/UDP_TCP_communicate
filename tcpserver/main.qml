import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2
import serverStream 1.0

Rectangle {
    width: 780
    height: 800
    color: "black"
    Item {
        id: display
        width: 200
        height: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        Image {
            id: su40
            source: "qrc:/images/images/su_40.jpg"
            visible: qstream.id === ServerStream.SPEED_LIMIT
        }
    }
    Image {
        id: right
        x:500
        source: "qrc:/images/images/right.jpg"
        visible: qstream.id === ServerStream.RIGHT
    }

    Image {
        id: left
        source: "qrc:/images/images/left.jpg"
        visible: qstream.id === ServerStream.LEFT
        ScriptAction{
            running: true
            script: {
                console.debug(ServerStream.LEFT);
                console.debug(qstream.id);
                console.debug("bbbbbbbbbbbbbb");}
        }
        Component.onCompleted: {
            console.debug("cccccccccccccccccccc");
        }
    }


    Component.onCompleted: {
        console.debug("aaaaaaaaaaaaaaaa");
    }

    SequentialAnimation{
        running: true
        ScriptAction{script: {
                console.debug("11111111111111111");}
        }
        ScriptAction{script: {
                console.debug("22222222222222222");}
        }
        ScriptAction{script: {
                console.debug("33333333333333333");}
        }
    }
}
