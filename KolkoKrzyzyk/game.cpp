#include "game.h"
#include "ui_game.h"
#include "board.h"

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    gameBoard = new board();
    setCurrentSignLabel();
    switchPostGameButtons(false);
}

game::~game()
{
    delete ui;
}

//ustawienie napisu wyznaczającego kolejny ruch
void game::setCurrentSignLabel(){
    char buffer[100];
    strcpy_s(buffer, "Kolejny ruch: ");
    strcat_s(buffer, board::sign_string(gameBoard->currentSign()));
    ui->labelGame->setText(buffer);
    ui->labelGame->setStyleSheet("");
}

//OBSŁUGA PRZYCISKÓW PLANSZY
//wrapper na obsługę przycisku planszy, który wykonuje ruch i jeśli był możliwy, ustawia w UI odpowiedni symbol oraz sprawdza stan gry
void game::setFieldAndButton(int idx, QPushButton* button){
    Sign sign = gameBoard->currentSign();
    if (gameBoard->makeMove(idx)){
        button->setText(board::sign_string(sign));
        State state = gameBoard->checkGame();
        switch (state){
            case X_WINNER:
                winnerFound(X);
                break;
            case O_WINNER:
                winnerFound(O);
                break;
            case DRAW:
                draw();
                break;
            case UNDECIDED:
                setCurrentSignLabel();
                break;
        }
    }
}

void game::on_buttonField0_clicked()
{
    setFieldAndButton(0, ui->buttonField0);
}


void game::on_buttonField1_clicked()
{
    setFieldAndButton(1, ui->buttonField1);
}


void game::on_buttonField2_clicked()
{
    setFieldAndButton(2, ui->buttonField2);
}


void game::on_buttonField3_clicked()
{
    setFieldAndButton(3, ui->buttonField3);
}


void game::on_buttonField4_clicked()
{
    setFieldAndButton(4, ui->buttonField4);
}


void game::on_buttonField5_clicked()
{
    setFieldAndButton(5, ui->buttonField5);
}


void game::on_buttonField6_clicked()
{
    setFieldAndButton(6, ui->buttonField6);
}


void game::on_buttonField7_clicked()
{
    setFieldAndButton(7, ui->buttonField7);
}


void game::on_buttonField8_clicked()
{
    setFieldAndButton(8, ui->buttonField8);
}

//dezaktywacja lub aktywacja przycisków planszy, w zależności od ich aktualnego stanu
void game::switchBoardButtons(){
    ui->buttonField0->setEnabled(!ui->buttonField0->isEnabled());
    ui->buttonField1->setEnabled(!ui->buttonField1->isEnabled());
    ui->buttonField2->setEnabled(!ui->buttonField2->isEnabled());
    ui->buttonField3->setEnabled(!ui->buttonField3->isEnabled());
    ui->buttonField4->setEnabled(!ui->buttonField4->isEnabled());
    ui->buttonField5->setEnabled(!ui->buttonField5->isEnabled());
    ui->buttonField6->setEnabled(!ui->buttonField6->isEnabled());
    ui->buttonField7->setEnabled(!ui->buttonField7->isEnabled());
    ui->buttonField8->setEnabled(!ui->buttonField8->isEnabled());
}

//resetowanie podpisów na przyciskach planszy oraz ich stanu
void game::resetBoardButtons(){
    switchBoardButtons();
    ui->buttonField0->setText("");
    ui->buttonField1->setText("");
    ui->buttonField2->setText("");
    ui->buttonField3->setText("");
    ui->buttonField4->setText("");
    ui->buttonField5->setText("");
    ui->buttonField6->setText("");
    ui->buttonField7->setText("");
    ui->buttonField8->setText("");
}


//OBSŁUGA PRZYCISKÓW KOŃCOWYCH
//schowanie lub pokazanie przycisków końcowych, w zależności od przekazanej zmiennej
void game::switchPostGameButtons(bool show){
    if (show){
        ui->buttonExit->setVisible(true);
        ui->buttonPlayAgain->setVisible(true);
    }
    else{
        ui->buttonExit->setVisible(false);
        ui->buttonPlayAgain->setVisible(false);
    }
}

//zagranie ponownie, czyli stworzenie nowej planszy, ustawienie napisu ruchu, schowanie przycisków końcowych oraz zresetowanie przycisków planszy
void game::playAgain(){
    gameBoard = new board();
    setCurrentSignLabel();
    switchPostGameButtons(false);
    resetBoardButtons();
}

//zamknij aplikację i zmień kolor przycisku Wyjdź
void game::on_buttonExit_clicked()
{
    ui->buttonExit->setStyleSheet("background-color: green;\nborder: none");
    this->close();
}

//zmiana koloru przycisku Wyjdź po kliknięciu
void game::on_buttonExit_pressed()
{
    ui->buttonExit->setStyleSheet("background-color: lightgreen;");
}

//zmiana koloru przycisku Zagraj Ponownie po kliknięciu
void game::on_buttonPlayAgain_pressed()
{
    ui->buttonPlayAgain->setStyleSheet("background-color: lightgreen;");
}

//rozpoczęcie kolejnej gry oraz zmiana koloru przycisku Zagraj Ponownie
void game::on_buttonPlayAgain_clicked()
{
    ui->buttonPlayAgain->setStyleSheet("background-color: green;\nborder: none");
    playAgain();
}

//ustawienie napisu oznaczającego zwycięzcę, pokazanie przycisków końcowych oraz dezaktywacja planszy
void game::winnerFound(Sign sign){
    char buffer[100];
    strcpy_s(buffer, "ZWYCIĘZCA: ");
    strcat_s(buffer, board::sign_string(sign));
    strcat_s(buffer, "!");
    ui->labelGame->setText(buffer);
    ui->labelGame->setStyleSheet("color: darkorange");
    switchBoardButtons();
    switchPostGameButtons(true);
}

//ustawienie napisu oznaczającego remis, pokazanie przycisków końcowych oraz dezaktywacja planszy
void game::draw(){
    ui->labelGame->setText("Remis.");
    ui->labelGame->setStyleSheet("color: purple");
    switchBoardButtons();
    switchPostGameButtons(true);
}

