#include "include/Board.h"
#include "include/Match.h"
#include "include/Cpu.h"
#include "include/Person.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
using namespace std;
using std::vector;

Match* match;

enum colors{
    GREEN = 0,
    YELLOW,
    RED,
    ORANGE,
    BLUE,
    PURPLE
    };

vector<Player*> createPlayers(int number);
string chooseColor(int number);
void drawBoard();
void createMatch(int numPlayers);
void startGame();
void gameLoop();
Cell* validateMove(vector<Cell*> moves, int row, int col);
Piece* selectPiece(Player* player);
void movePiece(Player* player);
void movePieceCPU(Player* player);
int get_int(int min, std::string prompt)
{
    int ret_integer;
    std::string str_number;

    while(true) {

        std::cout << prompt;
        std::getline(std::cin, str_number);
        std::stringstream convert(str_number);

        //checks for complete conversion to integer and checks for minimum value
        if(convert >> ret_integer && !(convert >> str_number) && ret_integer >= min && ret_integer <= 6) return ret_integer;

        std::cin.clear(); //just in case an error occurs with cin (eof(), etc)
        std::cerr << "At least 2 players and max 6 " << ". Try again.\n";
    }
}

int main()
{
    const int minPlayer=2; //example
    bool invalid = true;
    int numPlayers;
    while(invalid)
    {
        cout << "****************CHINESE CHECKERS****************" << endl;
        numPlayers=get_int(minPlayer, "    How many players(MAX 6):");
        if(numPlayers>1 && numPlayers<7){
            invalid = false;
        }
        system("cls");
    }
    createMatch(numPlayers);
    cout << match->getInformacionJugadores();
    match->assignPieces();
    system("pause");
    system("cls");

    gameLoop();

    return 0;
}


void gameLoop()
{
    bool noSalir = true;
    Player* player = nullptr;
    while(noSalir)
    {
        cout << "***************Chinese Checkers**************" << endl;
        drawBoard();
        player = match->getActualPlayer();
        //OHHHH
        if(player->getName().substr(0,1) == "C"){
            cout << "Computer's thinking..." << endl;
            movePieceCPU(player);
        }else{
            cout << "NOW: " << player->getName() << endl;
            movePiece(player);
        }

        system("pause");
        system("cls");
    }
}

void movePieceCPU(Player* player)
{
    bool cellFound = false;
    Piece* pieceSelected;

    while(!cellFound){
        pieceSelected = player->getRandomPiece();
        if(player != nullptr){
            vector<Cell*> moves  = match->getPiecePossibleMoves(pieceSelected->getCell()->getRow(), pieceSelected->getCell()->getColumn());
            if(moves.size() > 0){
                int random = rand() % moves.size();
                //Para estar mega seguros
                Cell* destination = validateMove(moves,moves[random]->getRow(),moves[random]->getColumn());
                if(destination != nullptr)
                {
                    match->movePiece(pieceSelected,destination);
                    cout << "My move: " << endl;
                    cout << "Column " << destination->getColumn() << endl;
                    cout << "Row " << destination->getRow() << endl;
                    cellFound = true;
                }
            }
        }

    }
}

void movePiece(Player* player)
{
    Piece* pieceSelected = selectPiece(player);
    if(pieceSelected != nullptr)
    {
        //Testing Method
        vector<Cell*> moves  = match->getPiecePossibleMoves(pieceSelected->getCell()->getRow(), pieceSelected->getCell()->getColumn());
        if(moves.size() > 0)
        {
            cout << "Possible moves for piece in " << 3 << "||" << 6 << endl;
            for(Cell* cell: moves)
            {
                cout << "Row: " << cell->getRow() << "|| Column: " << cell->getColumn() << endl;
            }
            cout << "******************************************" << endl;
            int row, col;
            string rowS, colS;
            cout << "Destination" << endl;
            cout << "Type the row: ";
            cin >> rowS;
            cout << "Type the column: ";
            cin >> colS;
            row = atoi( rowS.c_str() );
            col = atoi( colS.c_str() );
            Cell* destination = validateMove(moves,row,col);
            if(destination != nullptr)
            {
                cout << "Excelent move, you're on fire!!" << endl;
                match->movePiece(pieceSelected,destination);
            }
            else
            {
                cout << "Invalid move, Don't you know how to play?" << endl;
            }
        }
        else
        {
            cout << "There are not possible moves for this piece" << endl;
        }
    }
    else
    {
        cout << "Wrong piece" << endl;
    }

}

Cell* validateMove(vector<Cell*> moves, int row, int col)
{
    Cell* newCell = nullptr;
    for(Cell* cell:moves)
    {
        if(cell->getRow() == row && cell->getColumn() == col )
        {
            newCell = cell;
            break;
        }
    }
    return newCell;
}


Piece* selectPiece(Player* player)
{
    Piece* selectedPiece = nullptr;
    int row, col;
    string rowS, colS;
    cout << "Select one of your pieces" << endl;
    cout << "Type the row: ";
    cin >> rowS;
    cout << "Type the column: ";
    cin >> colS;
    row = atoi( rowS.c_str() );
    col = atoi( colS.c_str() );
    for(Piece* piece : player->getPieces())
    {
        if( piece->getCell()->getRow() == row && piece->getCell()->getColumn() == col  )
        {
            selectedPiece = piece;
            break;
        }
    }
    return selectedPiece;
}

void createMatch(int numPlayers)
{
    Board* board;
    vector<Player*> players = createPlayers(numPlayers);

    board = new Board(numPlayers);
    match = new Match(players, board);
}

vector<Player*> createPlayers(int number)
{
    vector<Player*> players(number);
    Player* player;
    string isThisHome;
    string isCpu;
    string color;
    bool home = false;
    bool CpuSelected = false;
    players.resize(number);

    cout << "************Players Configuration*************" << endl;
    cout << "       First is Home" << endl;
    for(int i=0; i < players.size(); i++)
    {
        if(i == 0)
        {
           home = true;
        }

        if(CpuSelected == false)
        {
            cout << "   Is Player #" << i+1 << " CPU(yes/no):";
            cin >> isCpu;
            if(isCpu == "yes")
            {
                color = chooseColor(i);
                player = new Cpu("C"+color, color, home);
                CpuSelected = true;
            }
            else
            {
                color = chooseColor(i);
                player = new Person("P"+color, chooseColor(i), home);
            }
        }
        else
        {
            color = chooseColor(i);
            player = new Person("P"+color, chooseColor(i), home);
        }
        players[i] = player;
        home = false;
    }
    system("cls");
    return players;
}

string chooseColor(int number)
{
    string color;
    switch(number)
    {
        case GREEN:
            color = "G";
            break;
        case YELLOW:
            color = "Y";
            break;
        case RED:
            color = "R";
            break;
        case ORANGE:
            color = "O";
            break;
        case BLUE:
            color = "B";
            break;
        default:
            color = "P";
            break;
    }
    return color;
}
void drawBoard()
{
    cout << endl << endl;
    const Board* board = match->getBoard();
    /*for(int i = 0; i < board->ROWS; i++)
    {
        for(int j = 0; j < board->COLUMNS; j++)
        {
            if(board->MAP[i][j] != -1 )
            {
                cout << "|__|";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl << endl;

    }
    */
    //Chinese Board
    string space;
    cout << "          1   2   3   4   5   6   7   8   9   10   11   12   13" << endl;
    for(int i = 0; i < 17; i++)
    {
        cout << i + 1;
        if(i==0 || i==16)
        {
            space = "                        ";
        }

        else if (i == 1 || i == 15)
        {
            space = "                      ";
        }
        else if (i == 2 || i == 14)
        {
            space = "                    ";
        }

        else if (i == 3 || i == 13)
        {
            space = "                  ";
        }

        else if (i == 5 || i == 11)
        {
            space = "  ";
        }

        else if (i == 6 || i == 10)
        {
            space = "    ";
        }

        else if (i == 7 || i == 9)
        {
            space = "      ";
        }

        else if (i == 8)
        {
            space = "        ";
        }

        cout << space +"        ";

        for(int j = 0; j < 13; j++)
        {
            if(board->map[i][j]->isValid())
            {
                if(board->map[i][j]->getPiece() != nullptr){
                    cout << "|" + board->map[i][j]->getPiece()->getColor() + "_|";
                }else{
                    cout << "|__|";
                }

            }
        }
        cout << endl << endl;
        space = "";
    }
}

