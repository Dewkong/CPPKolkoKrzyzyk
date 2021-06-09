#include "board.h"

//konstruktor, ustawiający wszystkie pola planszy na BLANK oraz początkowy symbol na O
board::board()
{
    for (int i = 0; i < 9; i++){
        fields[i] = BLANK;
    }
    now_O = true;
}

//funkcja statyczna, konwertująca enum symbolu na odpowiedni napis
const char* board::sign_string(Sign sign){
   switch(sign) {
      case BLANK:
         return " ";
      case X:
         return "X";
      case O:
         return "O";
      default:
         return "Invalid sign";
   }
}

//symbol na polu o podanym indeksie; zwraca BLANK jeśli jest poza zakresem planszy
Sign board::getField(int idx){
    if (idx < 0 || idx > 8){
        return BLANK;
    }
    return fields[idx];
}

//symbol, który ma wykonać teraz ruch
Sign board::currentSign(){
    return now_O ? O : X;
}

//wykonywanie ruchu na pole o danym indeksie; zwraca 0 przy błędzie oraz 1 przy sukcesie
int board::makeMove(int idx){
    if (idx < 0 || idx > 8){
        return 0;
    }
    if (getField(idx) != BLANK){
        return 0;
    }
    fields[idx] = currentSign();
    now_O = !now_O;
    return 1;
}

//szukanie potencjalnego zwycięzcy; zwraca BLANK jeśli ani X ani O jeszce nie wygrywa
Sign board::checkWinner(){
    Sign first;
    Sign second;
    Sign third;
    //poziomo
    for (int i = 0; i < 3; i++){
        first = getField(3 * i);
        second = getField(3 * i + 1);
        third = getField(3 * i + 2);
        if (first != BLANK && first == second && second == third){
            return first;
        }
    }
    //pionowo
    for (int i = 0; i < 3; i++){
        first = getField(i);
        second = getField(i + 3);
        third = getField(i + 6);
        if (first != BLANK && first == second && second == third){
            return first;
        }
    }
    //po skosie do gory
    first = getField(6);
    second = getField(4);
    third = getField(2);
    if (first != BLANK && first == second && second == third){
        return first;
    }
    //po skosie w dol
    first = getField(0);
    second = getField(4);
    third = getField(8);
    if (first != BLANK && first == second && second == third){
        return first;
    }
    return BLANK;
}

//ilość niepustych pól na planszy
int board::numberOfNonBlanks(){
    int sum = 0;
    for (int i = 0; i < 9; i++){
        if (getField(i) != BLANK){
            sum++;
        }
    }
    return sum;
}

//sprawdzanie stanu gry
State board::checkGame(){
    Sign winner = checkWinner();
    if (winner == X){
        return X_WINNER;
    }
    else if (winner == O){
        return O_WINNER;
    }
    else if (numberOfNonBlanks() == 9){
        return DRAW;
    }
    else{
        return UNDECIDED;
    }
}


