#include "player.h"
#include "download.h"
#include <QDebug>
#include <QMediaMetaData>
Player::Player(QObject *parent) : QObject(parent)
{
    currentIndex=-1;
    //playlist = new QMediaPlaylist();
    mediaPlayer = new QMediaPlayer();
    mediaPlayer->setVolume(50);
    connect(mediaPlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(playNextSong()));

}
Player::~Player(){
    delete mediaPlayer;
}

void Player::addSong(QString filePath){
    qDebug()<<"Added Song"<<filePath;
    musicList.append(filePath);
    if (musicList.size() == 1){
        startPlaylist();
        play();
    }
    else if (musicList.size()>1 && musicList.size()<=currentIndex+1){
        mediaPlayer->setMedia(QUrl::fromLocalFile(musicList[++currentIndex]));
        play();
    }

}

void Player::play(){
    qDebug()<<"Playing Song";
    mediaPlayer->play();
}

void Player::pause(){
    qDebug()<<"Paused Song";
    mediaPlayer->pause();
}

void Player::previous(){
    currentIndex--;
    if (currentIndex > -1)
        mediaPlayer->setMedia(QUrl::fromLocalFile(musicList[currentIndex]));
}

void Player::next(){
    currentIndex++;
    if (currentIndex < musicList.size())
        mediaPlayer->setMedia(QUrl::fromLocalFile(musicList[currentIndex]));
}

void Player::startPlaylist(){
    if (musicList.empty()){
        qDebug()<<"Music List is Empty";
        return;
    }
    currentIndex=0;
    mediaPlayer->setMedia(QUrl::fromLocalFile(musicList[currentIndex]));
    emit newSong();

}


void Player::playNextSong(){
    if (mediaPlayer->state() == QMediaPlayer::StoppedState){
        qDebug()<<"Stopped State";
        if (musicList.size()-1>currentIndex) { //Fails when going to be out of index
            mediaPlayer->setMedia(QUrl::fromLocalFile(musicList[++currentIndex]));
            play();
            emit newSong();
        }
    }
}

QString Player::getSongName(){

       QString title = mediaPlayer->metaData(QMediaMetaData::Title).toString();
       qDebug()<<title;
       return title;
}
