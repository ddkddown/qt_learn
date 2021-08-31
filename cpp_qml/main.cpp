#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ColorMaker.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<ColorMaker>("qt.ColorMaker", 1, 0, "ColorMaker");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("colorMaker2", new ColorMaker);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
