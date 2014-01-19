#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "netsettingsreader.h"


int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/template.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //
    // To display the view, call "show()" (will show fullscreen on device).
    QGuiApplication *app = SailfishApp::application(argc, argv);
    qmlRegisterType<NetSettingsReader>("harbour.wifipr.NetSettingsReader", 1, 0, "NetSettingsReader");

    QQuickView *view = SailfishApp::createView();

    QQmlContext *context = view->rootContext();
    NetSettingsReader *nr = new NetSettingsReader();
    view->rootContext()->setContextProperty("netsettingsreader", nr);
    view->setSource(SailfishApp::pathTo("qml/wifipr.qml"));

    view->show();

    //return SailfishApp::main(argc, argv);
    return app->exec();
}

