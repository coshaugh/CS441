#include "mainwindow.h"
#include <QApplication>
#include <clientuser.h>
#include <hostuser.h>
#include <server.h>
#include <user.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //

    HostUser Hello("fortune");
    ClientUser client("fortune");
    client.myClient->getConnection("fortune");
    client.myClient->sendMessage((QString)"Hello World");

    w.show();

    return a.exec();
}
