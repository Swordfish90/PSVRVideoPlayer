#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtQml>
#include <QWindow>
#include <QScreen>

#include <QDebug>

#include "qmlpsvr.h"
#include "psvrsensorsmanager.h"

void forceFullScreen(const QGuiApplication &app) {
    QWindow* window = app.allWindows().at(0);
    window->setVisibility(QWindow::Visibility::FullScreen);
}

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<QMLPSVR>("QMLPSVR", 0, 1, "QMLPSVR");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    forceFullScreen(app);

    return app.exec();
}
