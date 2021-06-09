#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


//główne okno aplikacji
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonExit_clicked();

    void on_buttonExit_pressed();

    void on_buttonPlay_pressed();

    void on_buttonPlay_clicked();

    void on_buttonPlay_released();

    void on_buttonExit_released();

private:
    Ui::MainWindow *ui;
    game *gameWindow;
};
#endif // MAINWINDOW_H
