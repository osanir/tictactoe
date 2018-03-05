#include "TicTacToeGame.h"

using namespace std;
TicTacToeGame::TicTacToeGame()
{
    //ctor
}

void TicTacToeGame::clearBoard(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            board[i][j] = '.';
    }
}

void TicTacToeGame::printBoard(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << " |1|2|3|" << endl;
    for(int i=0; i<3; i++){
        cout << "--------" << endl;
        cout << i+1;
        for(int j=0; j<3; j++){
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "--------" << endl;

}

int TicTacToeGame::getXCoor(){
    int x;
    cout << "Please input X coordinate: ";
    cin >> x;
    return x-1;
}

int TicTacToeGame::getYCoor(){
    int y;
    cout << "Please input Y coordinate: ";
    cin >> y;
    return y-1;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer){
    if( board[y][x] == '.' ){
        board[y][x] = currentPlayer;
        return 0;
    }
    else{
        cout << "Invalid Coordinate!" << endl;
        return 1;
    }

}

bool TicTacToeGame::checkVictory(){
    int counter=1;

    // check the rows
    for(int i=0; i<3; i++){
        counter = 1;
        for(int j=0; j<2; j++){
            // if this coordinate equal to empty spaces, do not do anything
            if( board[i][j] == '.')
                continue;

            if( board[i][j] == board[i][j+1])
                counter++;
            else
                counter = 1;
            if( counter >= 3)
                return 1;

        }
    }

    // check the colums
    counter = 1;
    for(int i=0; i<3; i++){
        counter = 1;
        for(int j=0; j<2; j++){
            // if this coordinate equal to empty spaces, do not do anything
            if( board[j][i] == '.')
                continue;

            if( board[j][i] == board[j+1][i])
                counter++;
            else
                counter = 1;
            if( counter >= 3)
                return 1;

        }
    }

    // check top left diagonal
    counter = 1;
    for(int i=0, j=0; i<2, j<2; i++, j++){
        if( board[i][j] == '.')
                continue;
        if( board[i][j] == board[i+1][j+1] )
            counter++;
        else
            counter = 1;
        if( counter >= 3)
                return 1;

    }

    // check top right diagonal
    counter = 1;
    for(int i=0, j=2; i<2, j>0; i++, j--){
        if( board[i][j] == '.')
                continue;
        if( board[i][j] == board[i+1][j-1] )
            counter++;
        else
            counter = 1;
        if( counter >= 3)
                return 1;

    }
    return 0;
}

