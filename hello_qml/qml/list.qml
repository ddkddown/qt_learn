import QtQuick 2.2

Item {
    children:[
        Text{
            text: "textOne";
        },
        Text{
            text: "textTwo";
        }
    ]

    Component.onCompleted:{
        for (var i = 0; i < children.length; i++)
            console.log("text of label ", i, " : ", children[i].text)
    }
}