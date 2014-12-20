#ifndef CELL_H
#define CELL_H
#include "Piece.h"
class Piece;
class Cell
{
    public:
        Cell(int row, int column, bool valid);
        virtual ~Cell();
        inline void setRow(int row){ _row = row;}
        inline int getRow(){return _row;}
        inline void setColumn(int column){ _column = column;}
        inline int getColumn(){return _column;}
        inline Piece* getPiece(){return _piece;}
        inline void setPiece(Piece* piece){ _piece = piece;}
        inline bool isEmpty(){return _piece == nullptr;}
        inline bool isValid(){return _valid;}
        inline void clean(){_piece = nullptr;}
    private:
        int _row;
        int _column;
        bool _valid;
        Piece* _piece;
};

#endif // CELL_H

