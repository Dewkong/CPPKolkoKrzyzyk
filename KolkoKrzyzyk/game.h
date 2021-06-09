#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QPushButton>
#include "board.h"

namespace Ui {
class game;
}

//drugie okno aplikacji - gra
class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();
    void setCurrentSignLabel();
    void setFieldAndButton(int idx, QPushButton* button);
    void winnerFound(Sign sign);
    void draw();
    void switchBoardButtons();
    void switchPostGameButtons(bool show);
    void playAgain();
    void resetBoardButtons();

private slots:
    void on_buttonField0_clicked();

    void on_buttonField1_clicked();

    void on_buttonField2_clicked();

    void on_buttonField3_clicked();

    void on_buttonField4_clicked();

    void on_buttonField5_clicked();

    void on_buttonField6_clicked();

    void on_buttonField7_clicked();

    void on_buttonField8_clicked();

    void on_buttonExit_clicked();

    void on_buttonPlayAgain_pressed();

    void on_buttonPlayAgain_clicked();

    void on_buttonExit_pressed();

private:
    Ui::game *ui;
    board *gameBoard;
};

#endif // GAME_H
