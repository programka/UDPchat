#ifndef UDPCLIENT1_H
#define UDPCLIENT1_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UDPClient1; }
QT_END_NAMESPACE

class UDPClient1 : public QMainWindow
{
    Q_OBJECT

public:
    UDPClient1(QWidget *parent = nullptr);
    ~UDPClient1();

public slots:
    void ReadingData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UDPClient1 *ui;
    QUdpSocket *udpSocket;
};
#endif // UDPCLIENT1_H
