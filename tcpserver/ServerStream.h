#ifndef IMAGESTREAM_H_
#define IMAGESTREAM_H_
#define PIC_WIDTH 800
#define PIC_HEIGHT 600

#include <QWidget>
#include <QLabel>
#include <iostream>
#include <QtGui/QPalette>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include<QUdpSocket>
#include<QTimer>



class ServerStream : public QObject{ //QWidget
    Q_OBJECT

    Q_PROPERTY(INDI_INFO id MEMBER m_id NOTIFY idChanged)

public:
    enum INDI_INFO{
        LEFT,
        RIGHT,
        SPEED_LIMIT,
    };
    Q_ENUMS(INDI_INFO)
    ServerStream(QObject *parent = 0);  //   QWidget *qw=0
//    ServerStream();
    ~ServerStream();
//    void changeFace();
    bool flag;

signals:
    void idChanged();
public slots:
    void getSocketImage();  //获取从服务器端传来的图片数据
    void conEstablished();//建立连接
    void dealConnection();
    void sendUDPIp();
    //       void disConnected();
    //      void serverDisCon();//服务器断开连接
private:
    QTcpServer server;
    QTcpSocket *socket;   //socket对象
    QUdpSocket *udpSocket;
    QLabel *ql_show;
    QByteArray imageData;   //存放接收到的图片数据的QByteArray
    QByteArray addressData;
    QHostAddress address;
    //      QTimer *timerConnect;
    bool hasReadHead;   //是否接收到了当前所接收图片的第一个数据包。
    long avalibleNum;
    void initNetWork();
    QTimer udpTimer ;
    bool headFlag;
    INDI_INFO m_id;

};

#endif
