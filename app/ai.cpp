#include "includes/ai.h"
#include "includes/player.h"
#include "game.h"

void Bot::randomizeShot(int &x, int &y){
    int random = Game::getGrid();
    while(true){
        x = (1 + (rand() % random)) - 1;
        y = (1 + (rand() % random)) - 1;
        if(x < random && y < random){
            break;
        }
    }
}