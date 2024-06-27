#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>

void drawBoard(std::string board){
    std::cout <<"------------------" << std::endl;
    std::cout <<"| " <<  board[0] << "  |  " << board[1] << "  |  " << board[2] << "  |" << std::endl;
    std::cout <<  "-----|-----|------" << std::endl;
    std::cout <<"| " <<  board[3] << "  |  " << board[4] << "  |  " << board[5]  << "  |"<< std::endl;
    std::cout << "-----|-----|------" << std::endl;
    std::cout <<"| " <<  board[6] << "  |  " << board[7] << "  |  " << board[8]  << "  |"<< std::endl;
    std::cout << "------------------" << std::endl;

}

int playerMove(char *board, char player){
    std::cout << "Player move: " ;
    int play;
    std::cin >> play;
    play--;


    if (play < 0 && play > 9){
        std::cout << "Enter a number between 1 and 9: " << '\n';
    }
    else{
        if (board[play] = ' '){
            board[play] = player;
        }
        else{
            std::cout << "Spot already taken";
        }
    }

}
int computerMove(char *board, char computer){
    int cplay = (rand() % 8) + 1;
    if (board[cplay] == ' '){
        board[cplay] = computer;
    }
    else{
        computerMove(board, computer);

    }



}

int checkWinner(char *board, char player, char computer){
    if (board[0] != ' ' && board[0] == board[1] && board[1]== board[2]){
        board[0] == player ? std::cout << "Winner is Player: " << player << "!" << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' << '\n';

    }
    else if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5]){
        board[0] == 'X' ? std::cout << "Winner is Player: " << player << "!" << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' <<  '\n';

    }
    else if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8]){
        board[0] == 'X' ? std::cout << "Winner is Player: " << player << "!" << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' << '\n';

    }
    else if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6]){
        board[0] == player ? std::cout << "Winner is Player: " << player << "!" << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' << '\n';

    }
    else if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7]){
        board[0] == player ? std::cout << "Winner is Player: " << player << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' << '\n';

    }
    else if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8]){
        board[0] == player ? std::cout << "Winner is Player: " << player << "!" << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' << '\n';

    }
    else  if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]){
        board[0] == player ? std::cout << "Winner is Player: " << player << "!" << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' << '\n';

    }
    else if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]){
        board[0] == player ? std::cout << "Winner is Player: " << player << "!" << '\n' << '\n': std::cout << "Winner is Player: " << computer<< "!" << '\n' << '\n';

    }
    else{
        return false;
    }
    return true;
}



int main(){

    char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char board1[9] = {'1','2','3','4','5','6','7','8','9'};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    std::cout << "-------------------" << '\n';
    std::cout << "*  TIC  TAC  TOE  *" << '\n';
    std::cout << "-------------------" << '\n';
    std::cout << "" << '\n';
    drawBoard(board1);
    std::cout << "Choose a number between 1 and 9" << '\n';
    drawBoard(board);
    while(running){
        playerMove(board, player);

        if (checkWinner(board, player,computer)){
            running = false;
            drawBoard(board);
            break;
        }
        computerMove(board, computer);
        drawBoard(board);
        if (checkWinner(board, player,computer)){
            running = false;
            break;
        }

    }

    return 0;
}

