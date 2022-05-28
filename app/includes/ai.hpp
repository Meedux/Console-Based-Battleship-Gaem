#ifndef _AI_HPP_
#define _AI_HPP_

#include <iostream>
#include <string>
#include "player.hpp"

class Bot: public Player {
    public:
    void randomizeShot();
};

#endif 