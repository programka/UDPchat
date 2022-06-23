#include "udpclient1.h"
#include "./ui_udpclient1.h"


UDPClient1::UDPClient1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UDPClient1)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, 1111);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(ReadingData()));
}

UDPClient1::~UDPClient1()
{
    delete ui;
}

void UDPClient1::ReadingData()
{
    QHostAddress sender;
    quint16 senderPort;

    while (udpSocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        ui->textEdit->append("<font color=red>" + QString(datagram) + "</font>");
        qDebug()<<datagram.data()<<"IP: " + sender.toString()<<"Port: "+QString("%1").arg(senderPort);
    }
}


void UDPClient1::on_pushButton_clicked()
{
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::LocalHost, 9999);
    ui->textEdit->append("Вы: <font color=cyan>" + ui->lineEdit->text() + "</font>");
    ui->lineEdit->clear();
}

