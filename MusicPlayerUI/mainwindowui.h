#ifndef MAINWINDOWUI_H
#define MAINWINDOWUI_H

#include <QMainWindow>
#include "playerui.h"


namespace Ui {
class MainWindowUI;
}

class MainWindowUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUI(QWidget *parent = 0);
    ~MainWindowUI();

private slots:
    void on_connectButton_clicked();

private:
    Ui::MainWindowUI *ui;
    playerUI*playerWindow;
};

#endif // MAINWINDOWUI_H
