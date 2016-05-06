#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = Q_NULLPTR);

private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();

    void enableSubmitLinkButton();
    void submitLink();

private:
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;

    QTcpSocket *tcpSocket;
    quint16 blockSize;

    QNetworkSession *networkSession;

    QLineEdit *linkEdit;
    QPushButton *submitLinkButton;
};

#endif

//#ifndef CLIENT_H
//#define CLIENT_H

//#include <qlocalsocket.h>

//QT_BEGIN_NAMESPACE
//class QLocalSocket;
//QT_END_NAMESPACE


//class Client : public QObject
//{
//    Q_OBJECT
//public:
//    explicit Client(QObject *parent = 0);
//    ~Client();
//public slots:
//    void getConnection(QString serverName);
//    void readMessage();
//    void sendMessage(QString message);

//private:
//    QLocalSocket *socket;
//    QString currentFortune;
//    quint16 blockSize;
//};

//#endif // CLIENT_H
