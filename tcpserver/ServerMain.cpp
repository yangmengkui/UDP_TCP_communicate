#include "ServerStream.h"
//#include <QtGui/QApplication>
#include <QApplication>
#include <QQmlContext>
#include<QQuickView>
#include<QtQml>
#include <QGuiApplication>
#include<QQmlEngine>
#include <QQmlComponent>
#include <QQmlApplicationEngine>

int main(int argc,char *argv[])
{
   QApplication a(argc,argv);
   ServerStream *stream = new ServerStream;
//   ServerStream serverstream;
//   stream->show();
   QQuickView viewer;
   viewer.rootContext()->setContextProperty("qstream",stream);
    qmlRegisterType<ServerStream>("serverStream", 1, 0, "ServerStream");
   viewer.setSource(QUrl("qrc:/main.qml"));
   viewer.show();
   return a.exec();
}
