#include "mainwindowui.h"
#include "ui_mainwindowui.h"

MainWindowUI::MainWindowUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowUI)
{
    ui->setupUi(this);
    ui->connectButton->setText("Connect");
}

MainWindowUI::~MainWindowUI()
{
    delete ui;
}
void MainWindowUI::on_connectButton_clicked()
{
    QString username = "John";
    QString validIP = "192.168.1.1";
    QString name = ui->nameBox->text();
    //int num = name.toInt();
    if (name == username)
    {
        QMessageBox::information(this, tr("Error Message"), tr("User name is already taken, please choose another one"));
//exit(0);

    }
    else
     {
    QString ip = ui->ipBox->text();

        if (ip != validIP )
    {
       QMessageBox::critical(this, tr("Error Message"), tr("Wrong IP address. Please try again"));

        //exit(0);
    }
    else {

        playerWindow =new playerUI(this);
        playerWindow->show();
        }
    }
