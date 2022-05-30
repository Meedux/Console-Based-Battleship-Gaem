#include "includes/game.h"
#include "includes/player.h"


Game::Game(){
    // to create a random sized map every round
    srand(time(0));
    grid = 10 + (rand() % 20);

    // For debugging purposes only
    // this->grid = 10;

    // Enemy AI and its Initialization of Properties and Variables
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

// The Main Loop
void Game::gameProcess(){

    int choice;
    while(choice != 4){
        // Render the UI
        menu();

        // Prompt the User to choose
        cout << "choice: ";
        cin >> choice;

        // Processing the input
        switch (choice)
        {
            // Game
            case 1:{
                initializeBoard();
                system("pause");
                system("cls");
                break;
            }
            // Multiplayer
            case 2:{
                system("cls");
                cout << "Multiplayer is not yet Available!" << endl;
                system("pause");
                system("cls");
                break;
            }
            // Guide
            case 3:{
                system("cls");
                printGuide();
                system("pause");
                system("cls");
                break;
            }
            // Exit
            case 4:{
                cout << "Thank you for Playing, The Program will now exit!" << endl;
                system("pause");
                system("cls");
                break;
            }

            // Will Catch the invalid inputs
            default:  {
                cerr << "Invalid Input Please try Again" << endl;
                system("pause");
                system("cls");
            }
        }
    }
}

// Outputting the Menu
void Game::menu(){
    cout << "\t\tWelcome to Battleship" << endl;
    cout << "\tA classic board game that's fun for the friend's and family :)" << endl;
    cout << "\t------------------------------------------------" << endl;
    cout << "\t\t(1)Offline Game(Player vs AI)" << endl;
    cout << "\t\t(2)Online Game(PvP)" << endl;
    cout << "\t\t(3)Guide" << endl;
    cout << "\t\t(4)Exit" << endl;
}

// Outputting the Guide
void Game::printGuide(){
    cout << "\t\t\tSo The Game has Two Phases, one is the Setup phase and one is the Missile Barrage phase\n\t\t\tThe First Phase(which is the Setup phase) will prompt you the player to input the position of the ships\n\t\t\tthis will have alot of checking if it goes out of board or intersects to another ship,\n\t\t\twe dont want that here and properly place your ships because they will lead you to victory\n\t\t\tin order to place the ships you will have to:\n\t\t\t\tSelect the Alignment of the Ship\n\t\t\t\tSelect the X and Y coordinate of the ship\n\t\t\tThe Game Will automatically place the ship depending on the alignment and the coordinates entered by the user\n\n\n\t\t\tFinally the Hit Phase,\n\t\t\tthis is the meat and potatoes of this game, You will be prompted to choose the specific coordinates to shoot the missile\n\t\t\tThere will be a symbol that will mark what happened in that coordinate\n\t\t\t\t'X' for Missed and,\n\t\t\t\t'O' for a solid Hit\n\t\t\tYou and The Enemy both had 19 health so be aware on where the enemy is...\n\n\n\n\t\t\tHave Fun :)....." << endl;
}


// Start of the Game
void Game::initializeBoard(){
    system("cls");

    Player playerOne;

    
    

    // Filling up the Boards in order to be rendered in the round
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

    // Setup Phase
    placeBoats(playerOne);
    placeEnemyBoats();

    // The Missile Barrage Phase/Game Loop
    game(playerOne);

    // Will Declare the Winner of the round
    endGame();
}

void Game::placeBoats(Player player){

    // Initializing the variables that will be utilized in the function
    int numOfBoats = 6;
    size_t num = 1;
    while(numOfBoats != 0){
        system("cls");
        // Will Render the board and rerender to update the board
        printPlayerOneBoard();
        cout << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << endl;
        player.getBoatNames();

        
        char align;
        int x, y;

        // Input of the Ships placement
        cout << "( Ship No. " << num << " )" << endl; 
        cout << "Enter an Alignment for " << num << "(h or v): ";
        cin >> align;
        cout << "Enter the Y Coordinate( 0 - " << (grid - 1) << " ): ";
        cin >> y;
        cout << "Enter the X Coordinate( 0 - " << (grid - 1) << " ): ";
        cin >> x;

        // Processing the Input
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
    // Will Act as a Loading screen
    cout << "Placing Enemy Ships..." << endl;
}

void Game::placeEnemyBoats(){
    

    int numOfBoats = 6;
    size_t num = 1;
    while(numOfBoats != 0){
        // Variables that will be utilized throughout the Function
        char alignList[2]{'v', 'h'};
        int x=0,y=0;
        int random = grid;

        // Randomized Alignment
        srand(time(NULL));
        char align = alignList[((rand() % 2))];

        // Randomized Coordinates
        while(true){
            x = (1 + (rand() % random)) - 1;
            y = (1 + (rand() % random)) - 1;
            if(x < random && y < random){
                break;
            }
        }

        // Processing the Randomized Variables
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

// Outputting the Board
void Game::printHiddenBoard(){
    for(auto &row: this->hiddenBoard){
        cout << "\t";
        for(auto &col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}

// Outputting the Board
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

// Outputting the Board
void Game::printPlayerTwoBoard(){

    for(auto &row: this->boardTwo){
        cout << "\t";
        for(auto &col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}


// Updating the Board
void Game::updatePlayerOneBoard(int x, int y){
    // Board Checking
    if(this->boardTwo[y][x] == 'X' || this->boardTwo[y][x] == 'O'){
        // This will be outputted if the coordinates has already been inputted
        cout << "Spot has been already shot, Try Again!"  << endl;
        system("pause");
    }else if(this->boardTwo[y][x] != '.'){
        // if it hits it will update the board and call the function that will update the global variables
        cout << "HIT!" << endl;
        this->boardTwo[y][x] = 'O';
        this->hiddenBoard[y][x] = 'O';
        this->current = false;
        checkBoardTwo();
        
        system("pause");
    }else{
        // if it misses it will just render 'X' and notifies that it missed
        cout << "Missed!" << endl;
        this->boardTwo[y][x] = 'X';
        this->hiddenBoard[y][x] = 'X';
        this->current = false;
        system("pause");
    }

}

void Game::updatePlayerTwoBoard(){
    // Intialization of variables that will be utilized throughout the function
    int x=0,y=0;
    int random = grid;

    // Generating a Randomized Coordinates
    while(true){
        x = (1 + (rand() % random)) - 1;
        y = (1 + (rand() % random)) - 1;
        if(x < random && y < random){
            break;
        }
    }

    // Same Semantics from the Player
    if(this->boardOne[y][x] == 'X' || this->boardOne[y][x] =='O'){
        // Do Nothing
    }else if(this->boardOne[y][x] != '.'){
        this->boardOne[y][x] = 'O';
        this->current = true;
        checkBoardOne();
        
    }else{
        this->boardOne[y][x] = 'X';
        this->current = true;
    }

}

// Checking of Boards and updating the global variables
void Game::checkBoardOne(){
    this->playerHealth--;
    if(this->playerHealth == 0){
        this->AIwin = true;
    }
}

// Checking of Boards and updating the global variables
void Game::checkBoardTwo(){
    this->AIhealth--;
    if(this->AIhealth == 0){
        this->playerOneWin = true;
    }
}

// Outputting the Board in a Formatted Way
void Game::printBoard(){
    system("cls");

    // To Be used for debugging purposes
    // printPlayerTwoBoard();

    printHiddenBoard();

    cout << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    printPlayerOneBoard();
}


// Game Loop
void Game::game(Player playerOne ){
    do{
        if(this->current){ //Check if the current turn is the player
            int x, y;
            printBoard();
            cout << "Enter the Y Coordinate to fire ( 0 - " << (grid - 1) << " ): ";
            cin >> y;
            cout << "Enter the X Coordinates to fire ( 0 - " << (grid - 1) << " ): ";
            cin >> x;

            // Check if the grid doesnt go overboard
            if(x > grid || y > grid){
                cout << "Invalid input!" << endl;
                system("pause");
            }else{
                updatePlayerOneBoard(x, y); //call in order to process and update the board based from the coordinates inputted by the user
            }
        }else{
            updatePlayerTwoBoard(); //the Process of the AI will be randomized and automated
        }

        // Checking of the global variables
        if(playerOneWin){
            break;
        }else if(AIwin){
            break;
        }

    }while(true);
}


// Declaring the winner of the Game!
void Game::endGame(){
    system("cls");
    if(playerOneWin){
        cout << "Player Wins!" << endl;
    }else if(AIwin){
        cout << "AI Wins!" << endl;
    }
}
