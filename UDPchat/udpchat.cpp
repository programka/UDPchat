#include "udpchat.h"
#include "./ui_udpchat.h"

UDPchat::UDPchat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UDPchat)
{
    ui->setupUi(this);
}

UDPchat::~UDPchat()
{
    delete ui;
}

void UDPchat::ReadingData()
{
    QHostAddress sender;
    quint16 senderPort;

    while (udpSocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        ui->ShowText->append("<font color=red>" + QString(datagram) + "</font>");
        qDebug()<<datagram.data()<<"IP: " + sender.toString()<<"Port: "+QString("%1").arg(senderPort);
    }
}


void UDPchat::on_Connect_button_clicked()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, ui->Port1_line->text().toUShort());
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(ReadingData()));
}


void UDPchat::on_Disconnect_button_clicked()
{
    ui->ShowText->clear();
    ui->Port1_line->clear();
    ui->Port2_line->clear();
    disconnect(udpSocket);
}


void UDPchat::on_Send_button_clicked()
{
    udpSocket->writeDatagram(ui->Send_line->text().toUtf8(), QHostAddress::LocalHost, ui->Port2_line->text().toUShort());
    ui->ShowText->append("Вы: <font color=blue>" + ui->Send_line->text() + "</font>");
    ui->Send_line->clear();
}

