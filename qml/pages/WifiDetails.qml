import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"

Page {
    id: page
    property string name
    property string passphrase
    property string lastip

    PageHeader {
        id: header
        title: qsTr("WIFI details")
    }
    SilicaFlickable{
        anchors{
            top: header.bottom
            left: parent.left
        }
        Column{
            width: page.width
            spacing: Theme.paddingMedium
            anchors{
                left: parent.left
                leftMargin: Theme.paddingLarge
                rightMargin: Theme.paddingLarge
            }

            ValueTitleItem{
                title: qsTr("SSID")
                text: name
            }
            ValueTitleItem{
                title: qsTr("Passphrase")
                text: passphrase? passphrase:qsTr("unknown")
            }

            ValueTitleItem{
                title: qsTr("Last IP:")
                text: lastip? lastip:qsTr("unknown")
            }
        }
    }
}
