#ifndef PLAYER_H
#define PLAYER_H
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QObject>
#include <QString>
#include <QList>
#include <QUrl>
class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    ~Player();
public slots:
    void addSong(QString filePath);
    void startPlaylist();
    void next();
    void previous();
    void play();
    void pause();
    void playNextSong();
    QString getSongName();
    qint64 getDuration();
    void setVolume(int newVolume);
signals:
    void playingNewSong();
private:
    int currentIndex;
    //QMediaPlaylist* playlist;
    bool stopBool;
    QMediaPlayer *mediaPlayer;
    QList<QString> musicList;

};

#endif // PLAYER_H
