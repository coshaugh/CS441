#include "mainwindow.h"
#include <QApplication>
#include <clientuser.h>
#include <hostuser.h>
#include <server.h>
#include <user.h>
#include <player.h>
#include <QString>

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
    QString filePath = "C:/Users/jappa_000/Downloads/ff7.mp3";

    musicPlayer.addSong(filePath);

    filePath = "C:/Users/jappa_000/Downloads/soundsOfdarkness.mp3";
    musicPlayer.addSong(filePath);
    musicPlayer.startPlaylist();
    musicPlayer.play();
    HostUser Hello("fortune");

    return a.exec();
}
