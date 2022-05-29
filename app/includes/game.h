#ifndef _GAME_H_
#define _GAME_H_

// #include "player.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>

using namespace std;


class Player;

struct Ship{
    int size;
    char symbol;
};

struct Bot{
    Ship AIships[6];
    int boatCount = 6;
};

class Game {
    private:
    int grid;

    bool current = true;

    bool playerOneWin = false;
    bool AIwin = false;

    Bot gameAI;

    vector< vector<char> > boardOne;
    vector< vector<char> > boardTwo;
    vector< vector<char> > hiddenBoard;
    public:
        Game();
        void gameProcess();
        void menu();

        void printPlayerOneBoard();
        void printPlayerTwoBoard();
        void printHiddenBoard();
        void updateHiddenBoard();
        void updatePlayerOneBoard(int x, int y);
        void updatePlayerTwoBoard();
        void checkBoardOne();
        void checkBoardTwo();

        void printGuide();

        void initializeBoard();
        void printBoard();
        void game(Player playerOne);
        void placeBoats(Player player);
        void placeEnemyBoats();
        void endGame();

        int getGrid(){
            return this->grid;
        }
};

#endif