#include "includes/player.h"



void Player::getBoatNames(){
    for(int i = 0; i < 6; i++){
        cout << "(" << (i + 1) << ")" << " " << boats[i].name << endl;
    }
}

char Player::getBoatSymbol(int index){
    return boats[index].symbol;
}

int Player::getBoatSize(int index){
    return boats[index].size;
}