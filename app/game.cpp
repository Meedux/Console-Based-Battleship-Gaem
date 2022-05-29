#include "includes/game.h"
#include "includes/player.h"

Game::Game(){
    srand(time(0));
    grid = 10 + (rand() % 20);

    for(size_t i = 0; i < 6; i++){
        Ship temp;
        gameAI.AIships[i] = temp;
    }

    gameAI.AIships[0].size = 2;
    gameAI.AIships[1].size = 2;
    gameAI.AIships[2].size = 3;
    gameAI.AIships[3].size = 3;
    gameAI.AIships[4].size = 4;
    gameAI.AIships[5].size = 5;

    gameAI.AIships[0].symbol = 'A';
    gameAI.AIships[1].symbol = 'B';
    gameAI.AIships[2].symbol = 'C';
    gameAI.AIships[3].symbol = 'D';
    gameAI.AIships[4].symbol = 'E';
    gameAI.AIships[5].symbol = 'F';

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
                system("pause");
                system("cls");
                break;
            }
            case 2:{
                system("cls");
                cout << "Multiplayer is not yet Available!" << endl;
                system("pause");
                system("cls");
                break;
            }
            case 3:{
                system("cls");
                printGuide();
                system("pause");
                system("cls");
                break;
            }
            case 4:{
                cout << "Thank you for Playing, The Program will now exit!" << endl;
                system("pause");
                system("cls");
                break;
            }
            default:  {
                cerr << "Invalid Input Please try Again" << endl;
                system("pause");
                system("cls");
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

void Game::printGuide(){
    cout << "\t\t\tSo The Game has Two Phases, one is the Setup phase and one is the Missile Barrage phase\n\t\t\tThe First Phase(which is the Setup phase) will prompt you the player to input the position of the ships\n\t\t\tthis will have alot of checking if it goes out of board or intersects to another ship,\n\t\t\twe dont want that here and properly place your ships because they will lead you to victory\n\n\n\t\t\tFinally the Missile Barrage Phase,\n\t\t\tthis is the meat and potatoes of this game, you will be prompted to bomp the f*** out of your enemies\n\t\t\thowever you will not see their ship's position\n\n\n\n\t\t\tHave Fun :)....." << endl;
}

void Game::initializeBoard(){
    system("cls");

    Player playerOne;

    
    


    boardOne.resize(grid);
    boardTwo.resize(grid);
    hiddenBoard.resize(grid);
    for(int i = 0; i < grid; i++){
        boardOne[i].resize(grid);
        for(int j = 0; j < grid; j++){
            boardOne[i][j] = '.';
        }

        boardTwo[i].resize(grid);
        for(int j = 0; j < grid; j++){
            boardTwo[i][j] = '.';
        }

        hiddenBoard[i].resize(grid);
        for(int j = 0; j < grid; j++){
            hiddenBoard[i][j] = '.';
        }
    }

    placeBoats(playerOne);
    placeEnemyBoats();
    game(playerOne);
    // printBoard();
    endGame();
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
        cout << "Enter the Y Coordinate( 0 - " << (grid - 1) << " ): ";
        cin >> y;
        cout << "Enter the X Coordinate( 0 - " << (grid - 1) << " ): ";
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
    

    cout << endl;
    cout << endl;
    cout << "Placing Enemy Ships..." << endl;
}

void Game::placeEnemyBoats(){
    

    int numOfBoats = 6;
    size_t num = 1;
    while(numOfBoats != 0){
        srand(time(NULL));
        char alignList[2]{'v', 'h'};
        char align = alignList[((rand() % 2))];
        int x=0,y=0;

        int random = grid;
        while(true){
            x = (1 + (rand() % random)) - 1;
            y = (1 + (rand() % random)) - 1;
            if(x < random && y < random){
                break;
            }
        }

        if(tolower(align) == 'h'){
            if(y - gameAI.AIships[(num - 1)].size >= 0){
                int intersected = 0;
                char sym = gameAI.AIships[(num - 1)].symbol;

                for(size_t i = 0; i < gameAI.AIships[(num - 1)].size; i++){
                    if(boardTwo[y][(x + i)] != '.' ){
                        intersected++;
                    }
                }

                if(intersected == 0){
                    for(size_t i = 0; i < gameAI.AIships[(num - 1)].size; i++){
                        boardTwo[(y - i)][x] = sym;
                    }
                    --numOfBoats;
                    ++num;
                }else{

                }

                
            }else{

            }
        }else if(tolower(align) == 'v'){
            if(x - gameAI.AIships[(num - 1)].size <= grid){
                int intersected = 0;
                char sym = gameAI.AIships[(num - 1)].symbol;
                for(size_t i = 0; i < gameAI.AIships[(num - 1)].size; i++){
                    if(boardTwo[y][(x + i)] != '.' ){
                        intersected++;
                    }
                }

                if(intersected == 0){
                    for(size_t i = 0; i < gameAI.AIships[(num - 1)].size; i++){
                        boardTwo[y][(x + i)] = sym;
                    }
                    --numOfBoats;
                    ++num;
                }else{
                   
                }

            }else{
                
            }
        }else{
            
        }
    }
}

void Game::printHiddenBoard(){
    for(auto &row: this->hiddenBoard){
        cout << "\t";
        for(auto &col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}

void Game::printPlayerOneBoard(){

    cout << "\t  ";
    for(int i = 0; i < grid; i++){
        cout << "X ";
    }
    cout << endl;
    for(auto &row: this->boardOne){
        cout << "\tY ";
        for(auto &col: row){ 
            cout << col << " ";
        }
        cout << endl;
    }
}

void Game::printPlayerTwoBoard(){

    for(auto &row: this->boardTwo){
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
        this->hiddenBoard[y][x] = 'O';
        this->current = false;
        system("pause");
    }else{
        this->boardTwo[y][x] = 'X';
        this->hiddenBoard[y][x] = 'X';
        this->current = false;
    }

    checkBoardTwo();
}

void Game::updatePlayerTwoBoard(){
    int x=0,y=0;

    int random = grid;
    while(true){
        x = (1 + (rand() % random)) - 1;
        y = (1 + (rand() % random)) - 1;
        if(x < random && y < random){
            break;
        }
    }

    if(this->boardOne[y][x] == 'X' || this->boardOne[y][x] =='O'){
        
    }else if(this->boardOne[y][x] != '.'){
        this->boardOne[y][x] = 'O';
        this->current = true;
    }else{
        this->boardOne[y][x] = 'X';
        this->current = true;
    }

    checkBoardOne();
}

void Game::checkBoardOne(){
    // int sunkenShip = 0;
    bool isAlive = false;
    char ships[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for(int i = 0; i < this->grid; i++){
        for(int j = 0; j < this->grid; j++){
            if(boardOne[i][j] == ships[i]){
                isAlive = true;
            }
        }
    }

    if(!isAlive){
        AIwin = true;
    }
}

void Game::checkBoardTwo(){
    bool isAlive = false;
    char ships[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for(int i = 0; i < this->grid; i++){
        for(int j = 0; j < this->grid; j++){
            if(boardOne[i][j] == ships[i]){
                isAlive = true;
            }
        }
    }

    if(!isAlive){
        playerOneWin = true;
    }
}

void Game::printBoard(){
    system("cls");
    printPlayerTwoBoard();
    // printHiddenBoard();

    cout << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    printPlayerOneBoard();
}

void Game::game(Player playerOne ){
    do{
        if(this->current){
            int x, y;
            printBoard();
            cout << "Enter the Y Coordinate to fire ( 0 - " << (grid - 1) << " ): ";
            cin >> y;
            cout << "Enter the X Coordinates to fire ( 0 - " << (grid - 1) << " ): ";
            cin >> x;

            if(x > grid || y > grid){
                cout << "Invalid input!" << endl;
                system("pause");
            }else{
                updatePlayerOneBoard((x - 1), (y - 1));
            }
        }else{
            updatePlayerTwoBoard();
        }

    }while(this->playerOneWin != true || this->AIwin != true);
}

void Game::endGame(){

}
