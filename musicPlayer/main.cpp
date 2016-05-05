#include "mainwindow.h"
#include <QApplication>
#include <clientuser.h>
#include <hostuser.h>
#include <server.h>
#include <user.h>
#include <player.h>
#include <QString>
#include "download.h"
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*
    HostUser Hello("fortune");
    ClientUser client("fortune");
    client.myClient->getConnection("fortune");
    client.myClient->sendMessage((QString)"Hello World");
*/

    Player musicPlayer;
    Download downloader;
    HostUser user("fortune");

    QObject::connect(user.myServer,SIGNAL(newMessage(QString)),&downloader,SLOT(downloadFile(QString)));

    QString filePath = "C:/Users/jappa_000/Downloads/ff7.mp3";

    musicPlayer.addSong(filePath);

    filePath = "C:/Users/jappa_000/Downloads/soundsOfdarkness.mp3";
    musicPlayer.addSong(filePath);
    musicPlayer.startPlaylist();
    musicPlayer.play();
    QString downloadLink = "https://www.youtube.com/watch?v=v-RE7RUzjf8";

    //downloader.downloadFile(downloadLink);

    return a.exec();
}
