#ifndef UDPCLIENT2_H
#define UDPCLIENT2_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UDPClient2; }
QT_END_NAMESPACE

class UDPClient2 : public QMainWindow
{
    Q_OBJECT

public:
    UDPClient2(QWidget *parent = nullptr);
    ~UDPClient2();

public slots:
    void ReadingData();

private slots:
    void on_bt_SendingData_clicked();

    void on_pushButton_clicked();

private:
    Ui::UDPClient2 *ui;
    QUdpSocket *udpSocket;
};
#endif // UDPCLIENT2_H
