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

//in order to create the said Objects within the Game class
class Player;

//For the Enemy AI
struct Ship{
    int size;
    char symbol;
};

// The Enemy AI
struct Bot{
    Ship AIships[6];
};

class Game {
    private:
    // Map Size Initialization
    int grid;

    // For Taking Turns between the player and the enemy AI
    bool current = true;

    // To Decide who's gonna be the winner
    bool playerOneWin = false;
    bool AIwin = false;

    // Both health are initialized within the Game class scope
    int AIhealth = 19;
    int playerHealth = 19;


    // Enemy Initialization
    Bot gameAI;

    // Enemy and Player Boards
    vector< vector<char> > boardOne;
    vector< vector<char> > boardTwo;

    // To be rendered for the enemy board in order for the ships to stay hidden
    vector< vector<char> > hiddenBoard;
    public:

        // Game Constructor
        Game();

        // Main Process
        void gameProcess();

        // Menu printing
        void menu();

        // Board printing, updating and checking
        void printPlayerOneBoard();
        void printPlayerTwoBoard();
        void printHiddenBoard();
        void updateHiddenBoard();
        void updatePlayerOneBoard(int x, int y);
        void updatePlayerTwoBoard();
        void checkBoardOne();
        void checkBoardTwo();

        // Game's Guide
        void printGuide();

        // Board initalization that will fill up the 2d vectors
        void initializeBoard();

        // Formatted Print of the two Boards
        void printBoard();

        // GameLoop
        void game(Player playerOne);

        // The Setup Phase
        void placeBoats(Player player);
        void placeEnemyBoats();

        // Finally the function that will declare the Winner
        void endGame();

        // Grid Getter Function
        int getGrid(){
            return this->grid;
        }
};

#endif