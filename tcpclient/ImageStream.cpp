#include "ImageStream.h"
#include <QTcpSocket>
#include <QtCore/QFile>
#include <QtCore/QByteArray>
#include <QTimer>
#include <QTime>
#include <QCoreApplication>
#include<stdio.h>
#include <QString>
//#include <qimage.h>

ImageStream::ImageStream(QWidget *qw) : QWidget(qw){
      initNetWork();
      timer = new QTimer(this);
      connect(timer,SIGNAL(timeout()),this,SLOT(count()));
}

ImageStream::~ImageStream(){

}

/*请求链接函数：以每秒2次的频率向服务器请求建立链接，
    当链接建立时停止发送请求。*/
void ImageStream::connecting()
{
    if(!flag){
//                client.connectToHost("192.168.1.119", 3333);
        client.connectToHost(serverIp.data(), 3333);
        std::cout << "客户端请求建立连接..." << std::endl;
    }
    else{
        timerConnect->stop();
    }
}
/*连接建立时调用该函数，停止发送建立连接的请求*/
void ImageStream::conEstablished()
{
    flag = true;
    std::cout<<"connect established!"<<std::endl;
}
/*当连接断开时，发送连接请求*/
void ImageStream::disConnected()
{
    client.close();
    flag = false;
    timerConnect->start(500);
}

void ImageStream::sendPictures()
{
    int num = 0;
    long len = 0;
    n = 0;
    timer->start(1000);
    for ( num = 1; num <= 97; num++){
        QFile file(":/images/images/test ("+QString::number(num)+").jpg"); //字符与数字的巧妙转换
        file.open(QIODevice::ReadOnly);
        QByteArray date;
        date = file.readAll();//读数据，返回一个字符数组
        len = date.length();    //一张图片的数据的字节数
//        std::cout << "len=" << len << std::endl;
        char headBuf[9] = {0};//
        snprintf(headBuf,9,"%08x",len);//long to char
//        std::cout << "headBuf:" << headBuf[0] << headBuf[1] << headBuf[2] << headBuf[3]  << headBuf[4] << headBuf[5] << headBuf[6] << headBuf[7] << headBuf[8] << std::endl;
        date.prepend(headBuf);
//        std::cout << "date:" << date[0] << date[1] << date[2] << date[3]  << date[4]  << date[5] << date[6] << date[7] << date[8] << std::endl;
        len = client.write(date);
        client.flush();//立即把缓冲区的数据写到底层的网络套接字中，即立刻把数据发送出去。
//        std::cout << len << " bytes have been written!" << std::endl << std::endl;

        QTime t;
        t.start();
        while (t.elapsed()<80) {
            QCoreApplication::processEvents();
        }
        /***************************************/
        /* 把以上五行注释掉，即发送图片时不延时，定时器timer不能正常工作；
             不注释掉以上五行，定时器timer正常工作*/
        /***************************************/
        if(num == 97) num = 0;
        if(-1 == len)
        {
            client.close();
            std::cout << "连接断开，请重新接入." << std::endl;
            break;
        }
         n++;
    }
}

void ImageStream::count()
{
    std::cout << "***************************************n=" << n << std::endl;
    n = 0;
}

void ImageStream::readData()
{
    udpClientSocket.readDatagram(serverIp.data(),512,&sendAddress,&sendPort);
    qDebug()<<serverIp.data();
    qDebug()<<sendAddress;
    qDebug()<<sendPort;
}

void ImageStream::initNetWork(){
    std::cout<<"initing network"<<std::endl;
//    QString serverIp;
    udpClientSocket.bind(6666,QAbstractSocket::ShareAddress);
    connect(&udpClientSocket,SIGNAL(readyRead()),this,SLOT(readData()));
    client.setParent(this);
//        client.connectToHost("192.168.1.119", 3333);
    client.connectToHost(serverIp.data(), 3333);
    flag = false;
    timerConnect = new QTimer;
    timerConnect->start(500);
    connect(timerConnect,SIGNAL(timeout()),this,SLOT(connecting()));
    connect(&client,SIGNAL(connected()),this,SLOT(conEstablished()));
    connect(&client,SIGNAL(connected()),this,SLOT(sendPictures()));
    connect(&client,SIGNAL(disconnected()),this,SLOT(disConnected()));
    std::cout<<"network inited!"<<std::endl;
}


