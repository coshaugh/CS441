#ifndef PLAYERUI_H
#define PLAYERUI_H

#include <QDialog>
#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class playerUI;
}

class playerUI : public QDialog
{
    Q_OBJECT

public:
    explicit playerUI(QWidget *parent = 0);
    ~playerUI();

private slots:
    void on_sendLink_clicked();
    void on_clearLink_clicked();
    void openFile();
    void playFile();
    void info();

private:
    Ui::playerUI *ui;
    QMediaPlayer mediaPlayer;
};

#endif // PLAYERUI_H
