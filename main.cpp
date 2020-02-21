#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <auth.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<Auth>("Auth", 1, 0, "Auth");

    QObject::connect(&engine, &QQmlApplicationEngine::quit, &QGuiApplication::quit);

    engine.load(url);

    return app.exec();
}
