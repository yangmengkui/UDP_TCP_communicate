#ifndef IMAGESTREAM_H_
#define IMAGESTREAM_H_

#include <QWidget>
#include <QLabel>
#include <iostream>
#include <QtGui/QPalette>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include<QUdpSocket>

class ImageStream : public QWidget{
   Q_OBJECT
   private:
      QHostAddress hostAddress;   //主机地址
      QTcpSocket client;   //socket对象    
      QUdpSocket udpClientSocket;
      QTimer *timerConnect;
        QTimer *timer ;
        QByteArray serverIp;
        QHostAddress sendAddress;
        quint16 sendPort;
      void initNetWork();
   public:
      ImageStream(QWidget *qw=0);
      ~ImageStream();
      bool flag;
      long n;
   public slots:
      void connecting();//请求建立连接
      void conEstablished();//建立连接
      void disConnected();
      void sendPictures();
      void count();
      void readData();
};

#endif
