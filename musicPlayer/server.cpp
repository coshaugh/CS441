#include "server.h"
#include <QtWidgets>
#include <QtNetwork>
#include <stdlib.h>
#include <QDebug>
Server::Server(QWidget *parent)
    : QDialog(parent)
    , myServer(Q_NULLPTR)
    , clientConnection(0)
    , blockSize(0)
{
    totalRequests=0;
    myServer = new QLocalServer(this);
    if (!myServer->listen(name)) {
        qDebug()<<"Can't Start Server";
        return;
    }
    //connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(myServer, SIGNAL(newConnection()), this, SLOT(receiveConnection()));
    connect(this,SIGNAL(newMessage(QString)),this,SLOT(test(QString)));
    qDebug()<<"Started Server "<<name;
}
Server::~Server()
{
    qDebug()<<"Deleted Server";
    delete myServer;
}

void Server::receiveConnection(){
    qDebug()<<"Recieved Connection";
    clientConnection = myServer->nextPendingConnection();

    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);
    connect(clientConnection, &QIODevice::readyRead, this, &Server::readMessage);

}

void Server::readMessage()
{
    qDebug()<<"Started Reading Message";
    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_4_0);
    if (blockSize == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    qDebug()<<"Finished Reading Message";

    QString message;
    in >> message;
    message= message.remove(QChar('\"'));
    qDebug()<<"Recieved Message is "<< message;

    clientConnection->disconnectFromHost();
    blockSize = 0;

}

void Server::sessionOpened()
{
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen()) {
        QMessageBox::critical(this, tr("Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Fortune Client example now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
}
