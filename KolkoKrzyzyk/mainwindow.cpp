#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//zamknij aplikację po kliknięciu Wyjdź
void MainWindow::on_buttonExit_clicked()
{
    this->close();
}

//zmiana koloru przycisku Wyjdź po kliknięciu
void MainWindow::on_buttonExit_pressed()
{
    ui->buttonExit->setStyleSheet("background-color: lightgreen;");
}

//zmiana koloru przycisku Zagraj po kliknięciu
void MainWindow::on_buttonPlay_pressed()
{
    ui->buttonPlay->setStyleSheet("background-color: lightgreen;");
}

//zmiana koloru przycisku Zagraj po puszczeniu
void MainWindow::on_buttonPlay_released()
{
   ui->buttonPlay->setStyleSheet("background-color: green;");
}

//zmiana koloru przycisku Wyjdź po puszczeniu
void MainWindow::on_buttonExit_released()
{
    ui->buttonExit->setStyleSheet("background-color: green;");
}

//zmiana okna na grę po naciśnięciu na przycisk Zagraj
void MainWindow::on_buttonPlay_clicked()
{
    this->hide();
    gameWindow = new game(this);
    gameWindow->show();
}


