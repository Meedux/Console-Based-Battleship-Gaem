#include "includes/game.hpp"

void Game::gameProcess(){
    // Render the UI
    
    int choice;
    while(choice != 4){
        menu();
        cout << "choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:{
                initializeBoard();
                break;
            }
            case 2:{

                break;
            }
            case 3:{

                break;
            }
            case 4:{

                break;
            }
            default:  {

            } 
        }
    }
}

void Game::menu(){
    cout << "\t\tWelcome to Battleship" << endl;
    cout << "\tA classic board game that's fun for the friend's and family :)" << endl;
    cout << "\t------------------------------------------------" << endl;
    cout << "\t\t(1)Offline Game(Player vs AI)" << endl;
    cout << "\t\t(2)Online Game(PvP)" << endl;
    cout << "\t\t(3)Guide" << endl;
    cout << "\t\t(4)Exit" << endl;
}

void Game::initializeBoard(){
    system("cls");
    

    // Figure out how to use vectors in this situation


    for(int i = 0; i < grid; i++){
        vector<char> tempOne;
        vector<char> tempTwo;

        for(int j = 0; j < grid; j++){
            tempOne.push_back('*');
        }
        boardOne.push_back(tempOne);

        for(int j = 0; j < grid; j++){
            tempTwo.push_back('*');
        }
        boardTwo.push_back(tempTwo);
    }

    // board.push_back(boardOne);
    // board.push_back(boardTwo);

    // cout << "\t";
    // for(int i = 0; i < grid; i++){
    //     cout << i;
    // }
    // cout << endl;


    for(int i = 0; i < grid; i++){
        cout << "\t";
        for(int j = 0; j < grid; j++){
            cout << boardTwo[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    // cout << "\t";
    // for(int i = 0; i < grid; i++){
    //     cout << i << " ";
    // }
    // cout << endl;

    for(int i = 0; i < grid; i++){
        cout << "\t";
        for(int j = 0; j < grid; j++){
            cout << boardOne[i][j] << " ";
        }
        cout << endl;
    }
}

void Game::updateBoard(){

}

void Game::endGame(){
    
}