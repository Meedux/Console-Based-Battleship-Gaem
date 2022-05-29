#include "includes/game.h"
#include "includes/player.h"

Game::Game(){
    srand(time(0));
    grid = 10 + (rand() % 20);

}

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

    Player playerOne;
    Bot enemy;

    
    


    boardOne.resize(grid);
    boardTwo.resize(grid);
    for(int i = 0; i < grid; i++){
        boardOne[i].resize(grid);
        for(int j = 0; j < grid; j++){
            boardOne[i][j] = '.';
        }

        boardTwo[i].resize(grid);
        for(int j = 0; j < grid; j++){
            boardTwo[i][j] = '.';

        }
    }

    placeBoats(playerOne);
    game(playerOne, enemy);
    // printBoard();
}

void Game::placeBoats(Player player){
    int numOfBoats = 6;
    size_t num = 1;
    while(numOfBoats != 0){
        system("cls");
        printPlayerOneBoard();
        cout << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << endl;
        player.getBoatNames();

        
        char align;
        int x, y;
        cout << "( Ship No. " << num << " )" << endl; 
        cout << "Enter an Alignment for " << num << "(h or v): ";
        cin >> align;
        cout << "Enter the Y Coordinate( 1 - " << grid << " ): ";
        cin >> y;
        cout << "Enter the X Coordinate( 1 - " << grid << " ): ";
        cin >> x;

        if(tolower(align) == 'h'){
            if(y - player.getBoatSize((num - 1)) >= 0){
                int intersected = 0;
                char sym = player.getBoatSymbol((num - 1));

                for(size_t i = 0; i < player.getBoatSize((num - 1)); i++){
                    if(boardOne[y][(x + i)] != '.' ){
                        intersected++;
                    }
                }

                if(intersected == 0){
                    for(size_t i = 0; i < player.getBoatSize((num - 1)); i++){
                        boardOne[(y - i)][x] = sym;
                    }
                    --numOfBoats;
                    ++num;
                }else{
                    cerr << "Cannot Place the Ship there!" << endl;
                    system("pause");
                }

                
            }else{
                cerr << "Cannot Place the Ship there!" << endl;
                system("pause");
            }
        }else if(tolower(align) == 'v'){
            if(x - player.getBoatSize((num - 1)) <= grid){
                int intersected = 0;
                char sym = player.getBoatSymbol((num - 1));
                for(size_t i = 0; i < player.getBoatSize((num - 1)); i++){
                    if(boardOne[y][(x + i)] != '.' ){
                        intersected++;
                    }
                }

                if(intersected == 0){
                    for(size_t i = 0; i < player.getBoatSize((num - 1)); i++){
                        boardOne[y][(x + i)] = sym;
                    }
                    --numOfBoats;
                    ++num;
                }else{
                    cerr << "Cannot Place the Ship there!" << endl;
                    system("pause");
                }

            }else{
                cerr << "Cannot Place the Ship there!" << endl;
                system("pause");
            }
        }else{
            cerr << "invalid input please try again..." << endl;
            system("pause");
        }
    }
    
}

void Game::printPlayerOneBoard(){

    for(auto &row: boardOne){
        cout << "\t";
        for(auto &col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}

void Game::printPlayerTwoBoard(){

    for(auto &row: boardTwo){
        cout << "\t";
        for(auto &col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}


void Game::updatePlayerOneBoard(int x, int y){
    if(this->boardTwo[y][x] == 'X' || this->boardTwo[y][x] =='O'){
        cout << "Spot has been already shot, Try Again!"  << endl;
        system("pause");
    }else if(this->boardTwo[y][x] != '.'){
        cout << "HIT!" << endl;
        this->boardTwo[y][x] = 'O';
        this->current = false;
        system("pause");
    }else{
        this->boardTwo[y][x] = 'X';
        this->current = false;
    }
}

void Game::updatePlayerTwoBoard(Bot enemy){
    int x=0,y=0;
    enemy.randomizeShot(x, y);
    if(this->boardOne[y][x] == 'X' || this->boardOne[y][x] =='O'){
        
    }else if(this->boardOne[y][x] != '.'){
        this->boardOne[y][x] = 'O';
        this->current = false;
    }else{
        this->boardOne[y][x] = 'X';
        this->current = false;
    }
    this->current = true;
}

void Game::printBoard(){
    system("cls");
    printPlayerTwoBoard();

    cout << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    printPlayerOneBoard();
}

void Game::game(Player playerOne, Bot enemy){
    do{

        if(this->current){
            int x, y;
            printBoard();
            cout << "Enter the Y Coordinate to fire ( 1 - " << grid << " ): ";
            cin >> y;
            cout << "Enter the X Coordinates to fire ( 1 - " << grid << " ): ";
            cin >> x;

            if(x > grid || y > grid){
                cout << "Invalid input!" << endl;
                system("pause");
            }else{
                updatePlayerOneBoard((x - 1), (y - 1));
            }
        }else{
            updatePlayerTwoBoard(enemy);
        }

    }while(playerOne.checkPlayer() || enemy.checkPlayer());
}

void Game::endGame(){

}
