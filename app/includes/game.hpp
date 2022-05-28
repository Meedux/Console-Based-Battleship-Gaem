#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>

using namespace std;


class Game {
    private:
    int grid;

    //figure out an alternative for this
    vector< vector<char> > boardOne;
    vector< vector<char> > boardTwo;
    public:
        Game(){
            srand(time(0));
            grid = 15 + (rand() % 50);
        }
        void gameProcess();
        void menu();
        void printPlayerOneBoard();
        void printPlayerTwoBoard();
        void updatePlayerOneBoard();
        void updatePlayerTwoBoard();
        void initializeBoard();
        void updateBoard();
        void endGame();

        int getGrid(){
            return grid;
        }
};

#endif