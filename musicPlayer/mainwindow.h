#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <client.h>
#include <player.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPlayer(Player*);

private slots:
    void on_PauseButton_clicked();

    void on_PlayButton_clicked();

private:
    Ui::MainWindow *ui;
    Player* _player;

};

#endif // MAINWINDOW_H
