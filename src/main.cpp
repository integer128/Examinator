#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "user.h"
#include "Theory.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<User>("User", 1, 0, "User");
    qmlRegisterType<Theory>("Theory", 1, 0 , "Theory");

    QObject::connect(&engine, &QQmlApplicationEngine::quit, &QGuiApplication::quit);

    engine.load(url);

    return app.exec();
}
