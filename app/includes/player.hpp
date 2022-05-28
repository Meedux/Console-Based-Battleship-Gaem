#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>

using namespace std;

struct Boat{
    int size;
    char symbol;
};

class Player
{
    private:
        Boat boats[6];
        int boatCount{6};

    public:
        Player(){
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
        }

        bool fire(int x, int y);
        bool checkPlayer();
};


#endif PLAYER