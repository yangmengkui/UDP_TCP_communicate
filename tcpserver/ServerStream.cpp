#include "ServerStream.h"
#include <QTcpSocket>
#include <QtCore/QFile>
#include <QtCore/QByteArray>
#include <QTimer>
#include<QHostInfo>
#include<QNetworkInterface>
#define UDPPort 6666
#define HOSTPORT 3333

ServerStream::ServerStream(QObject *parent ) : QObject(parent)
{
    initNetWork();
}

ServerStream::~ServerStream(){

}

void ServerStream::getSocketImage()
{
    //    QByteArray recvData = socket->readAll();
    QString head = socket->read(13);
    if("autorock-head" == head)
    {
        headFlag = true;
        qDebug()<<"head is finded\n";
    }
    if(headFlag ==true)
    {
        bool ok;
        m_id = (INDI_INFO)socket->read(8).toInt(&ok,16);
        qDebug()<<m_id;
        emit idChanged();
    }
}

void ServerStream::dealConnection()
{
    socket = server.nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(getSocketImage()));
    std::cout << "in dealConnection11111111111111111111" << std::endl << std::endl;
}

void ServerStream::conEstablished()
{
    //    flag = true;
    std::cout << "connect established!" << std::endl;
}

void ServerStream::sendUDPIp()
{
    qDebug()<<"udpTimer has started";
    udpSocket->writeDatagram(addressData,QHostAddress::Broadcast,UDPPort);
}

//初始化网络
void ServerStream::initNetWork(){
    std::cout << "initing network" << std::endl;
    socket = new QTcpSocket;
    udpSocket = new QUdpSocket;
    QString localHostName = QHostInfo::localHostName();
    qDebug()<<localHostName;
    /*QHostAddress*/ address=QNetworkInterface::allAddresses().at(2);
    qDebug()<<address;
    QString ipAddress = address.toString();
    qDebug()<<ipAddress;
    QString IP_PORT;
    IP_PORT = QString("autorock-alive") + ":" +  ipAddress + ":" + QString::number(HOSTPORT);
    addressData = IP_PORT.toLatin1();
    qDebug()<<addressData;
    //    QByteArray addressData;
    udpSocket->writeDatagram(addressData,QHostAddress::Broadcast,UDPPort);
    udpTimer.start(1000);
    connect(&udpTimer,SIGNAL(timeout()),this,SLOT(sendUDPIp()));

    server.setParent(this);
    server.listen(QHostAddress::Any,3333);
    connect(socket,SIGNAL(connected()),this,SLOT(conEstablished()));
    connect(&server,SIGNAL(newConnection()),this,SLOT(dealConnection()));
    std::cout << "network inited!" << std::endl;
    socket->setReadBufferSize(1024*1024);//设置接收端缓冲区大小
}




