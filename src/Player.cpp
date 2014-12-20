#include "../include/Player.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Player::Player(string name, string color, bool home): _name(name),
_color(color), _home(home),_pieces(10)
{

}

Piece* Player::findPieceAt(int row, int col)
{
    int cellRow;
    int cellCol;
    for(Piece* piece: _pieces){
        cellRow = piece->getCell()->getRow();
        cellCol = piece->getCell()->getColumn();
        if(cellRow == row && cellCol == col)
        {
           return piece;
        }
    }

    //not found
    return nullptr;
}

Piece* Player::getRandomPiece()
{
    srand ( time(NULL) );
    int random = rand() % _pieces.size();
    return _pieces[random];
}

Player::~Player()
{
    ///delete _pieces;
}

