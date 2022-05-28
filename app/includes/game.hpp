#ifndef GAME
#define GAME

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;



class Game {
    private:
    int grid = 15 + (rand() % 50);
    vector<vector<char>> board;

    public:
        void gameProcess();
        void initializeBoard();
        bool checkBoard();
        void updateBoard();
        void endGame();
};

#endif GAME