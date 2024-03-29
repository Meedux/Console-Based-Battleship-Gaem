#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include "game.h"

using namespace std;

// The Boat struct for the Player class
struct Boat{
    string name;
    int size;
    char symbol;
};

class Player: public Game{

        // to Store the Ships in an array
        Boat boats[6];

    public:

        // Player Initialization and it's properties
        Player(){
            for(size_t i = 0; i < 6; i++){
                Boat temp;
                boats[i] = temp;
            }
            boats[0].size = 2;
            boats[1].size = 2;
            boats[2].size = 3;
            boats[3].size = 3;
            boats[4].size = 4;
            boats[5].size = 5;

            boats[0].symbol = 'A';
            boats[1].symbol = 'B';
            boats[2].symbol = 'C';
            boats[3].symbol = 'D';
            boats[4].symbol = 'E';
            boats[5].symbol = 'F';

            boats[0].name = "Patrol Boat";
            boats[1].name = "Submarine";
            boats[2].name = "Cruiser";
            boats[3].name = "Destroyer";
            boats[4].name = "Battleship";
            boats[5].name = "Aircraft Carrier";
        }

        // Getter Functions
        char getBoatSymbol(int index);
        int getBoatSize(int index);
        void getBoatNames();
};


#endif 