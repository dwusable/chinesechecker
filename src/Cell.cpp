#include "../include/Cell.h"

Cell::Cell(int row, int column, bool valid): _row(row),
_column(column), _valid(valid), _piece(nullptr)
{}

Cell::~Cell()
{
    delete _piece;
}



