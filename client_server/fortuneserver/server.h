#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QComboBox;

class QTcpServer;
class QNetworkSession;
class QTcpSocket;
QT_END_NAMESPACE

class Server : public QDialog
{
    Q_OBJECT
public:
    explicit Server(QWidget *parent = Q_NULLPTR);

private slots:
    void sessionOpened();

    void storeLink();
    void readData();

private:
    QLabel *statusLabel;
    QComboBox *linkCombo;
    quint16 blockSize;

    QTcpServer *tcpServer;
    QNetworkSession *networkSession;
    QTcpSocket *tcpSocket;
};

#endif
