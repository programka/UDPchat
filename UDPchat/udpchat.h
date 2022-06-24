#ifndef UDPCHAT_H
#define UDPCHAT_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UDPchat; }
QT_END_NAMESPACE

class UDPchat : public QMainWindow
{
    Q_OBJECT

public:
    UDPchat(QWidget *parent = nullptr);
    ~UDPchat();

public slots:
    void ReadingData();

private slots:
    void on_Connect_button_clicked();

    void on_Disconnect_button_clicked();

    void on_Send_button_clicked();

private:
    Ui::UDPchat *ui;
    QUdpSocket *udpSocket;
};
#endif // UDPCHAT_H
