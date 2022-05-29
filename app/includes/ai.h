#ifndef _AI_H_
#define _AI_H_

#include <iostream>
#include <string>

class Player;
class Bot: public Player{
    public:
    void randomizeShot(int &x, int &y);
};

#endif 