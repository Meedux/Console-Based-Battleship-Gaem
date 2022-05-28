#ifndef AI
#define AI

#include <iostream>
#include <string>
#include <player.hpp>

class Bot: public Player {
    public:
    void randomizeShot();
};

#endif AI