#include <iostream>
#include "TicTacToeGame.h"

using namespace std;

int main()
{
    TicTacToeGame game;
    game.clearBoard();
//    game.printBoard();
    char player1 = 'X', player2 = 'O';
    int turn = 0;
    char currentPlayer = player1;
    int x, y;
    bool gameOver = false;

    while( !gameOver ){
        game.printBoard();

        cout << "Player " << currentPlayer << "'s turn. " << endl;
        // input X & Y coordinates
        do{
            x = game.getXCoor();
            y = game.getYCoor();
        }while( game.placeMarker(x, y, currentPlayer) );


        //switch player
        if(currentPlayer == player1)
            currentPlayer = player2;
        else
            currentPlayer = player1;



        gameOver = game.checkVictory();

        if(++turn == 9 && !gameOver){
            cout << "Game is over! Its a tie game." << endl;
            return 0;
        }
    }
    cout << "\n\n\n";
    game.printBoard();

    if(currentPlayer == player1)
        currentPlayer = player2;
    else
        currentPlayer = player1;

    cout << "Game is over! " <<  currentPlayer << " has won!" << endl;

    return 0;
}
