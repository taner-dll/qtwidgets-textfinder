#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

     loadTextFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     QString searchString = ui->lineEdit->text();
     //qDebug() << searchString;
     ui->textEdit->find(searchString, QTextDocument::FindCaseSensitively);


}


void MainWindow::loadTextFile()
{
    //dosya aç
//    QFile inputFile(QCoreApplication::applicationDirPath() +"/a.txt");
    QFile inputFile(":/a.txt");
    inputFile.open(QIODevice::ReadOnly);

    //read characters from stream
    QTextStream in(&inputFile);
    QString lines = in.readAll();
    //inputFile.close();

    //set textedit lines
    ui->textEdit->setPlainText(lines);

    //kürsör (imleç) konumunu ayarla
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
