import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.wifipr.NetSettingsReader 1.0

Page {
    id: page
    Component.onCompleted: {
        networkListModel.append(netsettingsreader.getNetworkList)
    }
    ListModel {
        id: networkListModel
    }
    SilicaListView {
        width: page.width
        anchors {
            top: parent.top
            fill: parent
        }
        model: networkListModel
        header: PageHeader { title: qsTr("Stored WIFI networks") }

        PullDownMenu {
            id: pullDownMenu

            MenuItem {
                text: qsTr("About")
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
                }
            }
        }
        VerticalScrollDecorator {}
        delegate: Item {
            id: myListItem
            width: parent.width - 2*Theme.paddingLarge
            height: wifiList.height
            Column{
                id: wifiList
                width: page.width
                anchors{
                    left: parent.left
                    leftMargin: Theme.paddingLarge
                    rightMargin: Theme.paddingLarge
                }
                BackgroundItem {
                    id: contentItem
                    onClicked: {
                        pageStack.push(Qt.resolvedUrl("WifiDetails.qml"), {name: name, passphrase: passphrase, lastip: lastip} )
                    }
                    Label {
                        id: lblName
                        text: name
                        color: Theme.primaryColor
                    }
                }
            }
        }
    }
}
