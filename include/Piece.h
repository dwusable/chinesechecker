#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include "Cell.h"
using namespace std;
class Cell;
class Piece
{
    public:
        Piece(string color);
        virtual ~Piece();
        inline void setColor(string color){ _color = color;}
        inline string getColor(){return _color;}
        inline void setCell(Cell* cell){ _cell = cell; }
        inline Cell* getCell(){ return _cell; }
    private:
        Cell* _cell;
        string _color;
};

#endif // PIECE_H

