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


class Bot;
class Player;
class Game {
    private:
    int grid;
    bool current = true;

    //figure out an alternative for this
    vector< vector<char> > boardOne;
    vector< vector<char> > boardTwo;
    public:
        Game();
        void gameProcess();
        void menu();
        void printPlayerOneBoard();
        void printPlayerTwoBoard();
        void updatePlayerOneBoard(int x, int y);
        void updatePlayerTwoBoard(Bot enemy);
        void initializeBoard();
        void printBoard();
        void game(Player playerOne, Bot enemy);
        void placeBoats(Player player);
        void endGame();

        int getGrid(){
            return grid;
        }
};

#endif