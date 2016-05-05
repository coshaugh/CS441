#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QString>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;

class QTcpServer;
class QNetworkSession;
class QTcpSocket;
QT_END_NAMESPACE


class Server : public QDialog
{
    Q_OBJECT
public:
    explicit Server(QWidget *parent = Q_NULLPTR);
    ~Server();

private slots:
    void sessionOpened();

    void readMessage();
    void receiveConnection();

private:
    QString messageBuffer;
    QString serverName;
    quint16 blockSize;

    int totalRequests;

    QTcpServer *myServer;
    QNetworkSession *clientConnection;
    QTcpSocket *tcpSocket;
};

#endif // SERVER_H
