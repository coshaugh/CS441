#include "mediator.h"
#include <QDebug>
Mediator::Mediator(Player* player,Download* download,HostUser* hostUser,QObject *parent):QObject(parent){
    this->_player = player;
    this->_download = download;
    this->_hostUser = hostUser;
    this-> currentlyDownloading = false;

    connect(_hostUser->myServer,SIGNAL(newMessage(QString)),this,SLOT(addQueue(QString)));
    connect(_download,SIGNAL(finishedDownloading(QString)),this,SLOT(downloadToPlayer(QString)));
    connect(_download,SIGNAL(finishedDownloading(QString)),this,SLOT(finishedDownload(QString)));

   // connect(this,SIGNAL(mediatorToDownload(QString)),this,SLOT(serverToDownload(QString)));
}

Mediator::~Mediator(){
    _player = NULL;
    _download = NULL;
    _hostUser = NULL;
}

void Mediator::download(){
    QString message="";
    if (currentlyDownloading == false && !downloadQueue.empty()){
        message = downloadQueue.first();
        downloadQueue.pop_front();
        if (message.contains("youtube", Qt::CaseInsensitive)){
            currentlyDownloading = true;
            _download->downloadYoutube(message);
        }
    }
}

void Mediator::downloadToPlayer(QString filePath){
    _player->addSong(filePath);
}

void Mediator::addQueue(QString item){
    downloadQueue.push_back(item);
    download();
}

void Mediator::finishedDownload(QString){
    currentlyDownloading = false;
    download();
}
