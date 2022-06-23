#include "udpclient2.h"
#include "./ui_udpclient2.h"

UDPClient2::UDPClient2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UDPClient2)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, 9999);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(ReadingData()));
}

UDPClient2::~UDPClient2()
{
    delete ui;
}

void UDPClient2::ReadingData()
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

void UDPClient2::on_bt_SendingData_clicked()
{
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::LocalHost, 1111);
    ui->textEdit->append("Вы: <font color=cyan>" + ui->lineEdit->text() + "</font>");
    ui->lineEdit->clear();
}


void UDPClient2::on_pushButton_clicked()
{
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::LocalHost, 1111);
    ui->textEdit->append("Вы: <font color=cyan>" + ui->lineEdit->text() + "</font>");
    ui->lineEdit->clear();
}

