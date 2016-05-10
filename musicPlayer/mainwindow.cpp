#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _player = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    _player = NULL;
}


void MainWindow::setPlayer(Player* player){
    this->_player = player;
}

void MainWindow::on_PauseButton_clicked()
{
    _player->pause();
}

void MainWindow::on_PlayButton_clicked()
{
    _player->play();
}
