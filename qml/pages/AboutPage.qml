import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"

Page {
    id: page
    Image {
        id: logo
        fillMode: Image.PreserveAspectCrop
        source: "../images/wifipr.png"
        anchors.horizontalCenter: parent.horizontalCenter
        y:150
    }
    SilicaFlickable{
        anchors{
            top: logo.bottom
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
            Label {
                id: appName
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                font.family: Theme.fontFamilyHeading
                color: Theme.highlightColor
                text: "WIFI password recovery 0.1"
            }
            Text {
                id: desc
                width: parent.width
                wrapMode: Text.WordWrap
                text: qsTr("Recovers the password for each stored WIFI network")
                color: Theme.primaryColor
            }
            ValueTitleItem{
                title:  qsTr("License")
                text: "GNU General Public License v3"
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("LicensePage.qml"))
                }
            }
            ValueTitleItem{
                title: qsTr("Author")
                text: "Tom Winterhalder"
                onClicked: {
                    openUrlPopup.openUrl("mailto:tom@winterhalder.ch?subject=WIFI Password recovery",qsTr("Starting mail app"))
                }
            }
            ValueTitleItem{
                title:  qsTr("Project page")
                text: "Github"
                onClicked: {
                    openUrlPopup.openUrl("https://github.com/thwint/wifipr")
                }
            }
            ValueTitleItem{
                title: qsTr("Donate")
                text: qsTr("via PayPal")
                onClicked: {
                    openUrlPopup.openUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=HVRWFMNFYM3LJ")
                }
            }
        }
    }
    RemorsePopup {
        id: openUrlPopup
        function openUrl(url, title) {
            openUrlPopup.execute(title || qsTr("Link will open"), function(){
                Qt.openUrlExternally(url);
            })
        }
    }
}
