#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <iostream>


class TicTacToeGame
{
    public:
        TicTacToeGame();

        void clearBoard();
        void printBoard();

        int getXCoor();
        int getYCoor();

        bool placeMarker(int x, int y, char currentPlayer);

        bool checkVictory();
    private:
        char board[3][3];
};

#endif // TICTACTOEGAME_H
