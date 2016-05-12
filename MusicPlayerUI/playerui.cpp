#include "playerui.h"
#include "ui_playerui.h"
#include <QWidget>

playerUI::playerUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playerUI)
{
    ui->setupUi(this);
}

playerUI::~playerUI()
{
    delete ui;
}

void playerUI::on_sendLink_clicked()
{
    QString url = ui->urlBox->text();
    //Send link
}

void playerUI::on_clearLink_clicked()
{
    ui->urlBox->setText("");
}

void playerUI::openFile()
{
    const QStringList musicPaths = QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    const QString filePath =
        QFileDialog::getOpenFileName(this, tr("Open File"),
                                     musicPaths.isEmpty() ? QDir::homePath() : musicPaths.first(),
                                     tr("MP3 files (*.mp3);;All files (*.*)"));
    if (!filePath.isEmpty())
        playFile(filePath);
}

void playerUI::playFile(const QString &filePath)
{
    playButton->setEnabled(true);
    infoLabel->setText(QFileInfo(filePath).fileName());

    mediaPlayer.setMedia(QUrl::fromLocalFile(filePath));
    mediaPlayer.play();
}

void playerUI::info()
{
    QString author = mediaPlayer.metaData("Author").toString();
    if (!author.isEmpty())
        //info += author;
        ui->artistName->setText(author);
    QString title = mediaPlayer.metaData("Title").toString();
    if (!title.isEmpty())
       // info += title;
        ui->songName->setText(title);
    /*if (!info.isEmpty())
        infoLabel->setText(info.join(tr(" - ")));
    */
}
