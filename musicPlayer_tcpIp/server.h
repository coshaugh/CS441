#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;
class QComboBox;
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

signals:
    void newMessage(QString link);

private:
    QLabel *statusLabel;
    QTcpServer *tcpServer;
    QNetworkSession *networkSession;
    QComboBox *linkCombo;
    quint16 blockSize;
    QTcpSocket *tcpSocket;
};

#endif


//#ifndef SERVER_H
//#define SERVER_H

//#include <QObject>
//#include <QDialog>
//#include <QString>
//#include <qlocalserver.h>
//#include <qlocalsocket.h>

//QT_BEGIN_NAMESPACE
//class QLabel;
//class QPushButton;
//class QLocalServer;
//QT_END_NAMESPACE


//class Server : public QObject
//{
//    Q_OBJECT
//public:
//    explicit Server(QString name,QObject *parent = 0);
//    ~Server();

//public slots:
//    QString readMessage(QLocalSocket* clientConnection);
//    void receiveConnection();

//private:
//    QString messageBuffer;
//    quint16 blockSize;
//    QString serverName;
//    int totalRequests;
//    QLocalServer *myServer;
//    QLocalSocket *clientConnection;
//signals:
//    void newMessage(QString message);

//};

//#endif // SERVER_H

