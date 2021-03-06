#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "user.h"
#include "Theory.h"
#include "testmodel.h"
#include "testresultsmodel.h"

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

    TestModel *tmodel { new TestModel{} };
    TestModel * allTests { new TestModel (tmodel->getAllTests()) };
    TestResultsModel * rtModel { new TestResultsModel };
    engine.rootContext()->setContextProperty("qa_model", tmodel);
    engine.rootContext()->setContextProperty("tr_model", rtModel);
    engine.rootContext()->setContextProperty("teditor", allTests);

    qmlRegisterType<User>("User", 1, 0, "User");
    qmlRegisterType<Theory>("Theory", 1, 0 , "Theory");

    QObject::connect(&engine, &QQmlApplicationEngine::quit, &QGuiApplication::quit);

    engine.load(url);

    return app.exec();
}
