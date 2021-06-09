#ifndef BOARD_H
#define BOARD_H

//enum odpowiedzialny za całą logikę symboli/znaków na planszy, BLANK oznacza puste pole
enum Sign {BLANK, X, O};

//enum używany przy wyznaczaniu zwycięzcy lub remisu
enum State {UNDECIDED, X_WINNER, O_WINNER, DRAW};


//klasa planszy, która zawiera całą logikę gry
class board
{
public:
    board();
    Sign currentSign();
    Sign getField(int idx);
    Sign checkWinner();
    int makeMove(int idx);
    int numberOfNonBlanks();
    State checkGame();
    static const char* sign_string(Sign sign);
private:
    Sign fields[9]; //jednowymiarowa tablica symboli, gdzie pola 0-2 to pierwszy wiersz planszy, 3-5 drugi, 6-8 trzeci
    bool now_O; //zmienna określająca, czyj ruch jest następny; gra zaczyna się od O
};

#endif // BOARD_H
