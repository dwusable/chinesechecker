#include "../include/Board.h"


Board::~Board()
{

}

Board::Board(int numPlayers): _numPlayers(numPlayers)
{
    createMap();
}

void fillMap(){

}

void Board::createMap()
{
    Cell* invalidCell = new Cell(-1, -1, false);
    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            if(i==0 || i==16)
            {
                if(j != 6)
                {
                    map[i][j]=invalidCell;
                }
            }
            else if (i == 1 || i == 15)
            {
                if (j < 5 || j > 6)
                {
                    map[i][j] = invalidCell;
                }
            }
            else if (i == 2 || i == 14)
            {
                if (j < 5 || j > 7)
                {
                    map[i][j] = invalidCell;
                }
            }

            else if (i == 3 || i == 13)
            {
                if (j < 4 || j > 7)
                {
                    map[i][j] = invalidCell;
                }
            }

            else if (i == 5 || i == 11)
            {
                if (j == 12)
                {
                    map[i][j] = invalidCell;
                }
            }

            else if (i == 6 || i == 10)
            {
                if (j == 0 || j == 12)
                    {
                    map[i][j] = invalidCell;
                }
            }

            else if (i == 7 || i == 9)
            {
                if (j < 1 || j > 10)
                {
                    map[i][j] = invalidCell;
                }
            }
            else if (i == 8)
            {
                if (j < 2 || j > 10)
                {
                    map[i][j] = invalidCell;
                }
            }


            if( map[i][j] != invalidCell)
            {
               map[i][j] = new Cell(i, j, true);
            }
        }
    }
}

vector<Cell*> Board::getPossibleMoves(Cell* from)
{
    vector<Cell*> availableCells;
    int row = from->getRow();
    int col = from->getColumn();
    if(row%2 == 0)
    {
        availableCells = availableCell(row, col, -1);
    }
    else
    {
        availableCells = availableCell(row, col, 1);
    }
    return availableCells;
}
//Direction 1 right, -1 left
vector<Cell*> Board::availableCell(int row, int col, int direction)
{
    vector<Cell*> cells;
    //Right
    if(map[row][col+1]->isEmpty() && map[row][col+1]->isValid())
    {
        //validacion campo extra
        cells.push_back(map[row][col+1]);
    }
    //Left
    if(map[row][col-1]->isEmpty() && map[row][col-1]->isValid())
    {
        cells.push_back( map[row][col-1]);
    }
    //Up
    if(map[row+1][col]->isEmpty() && map[row+1][col]->isValid())
    {
        cells.push_back(map[row+1][col]);
    }
    //Down
    if(map[row-1][col]->isEmpty() && map[row-1][col]->isValid())
    {
        cells.push_back( map[row-1][col]);
    }
    //UpRight or UpLeft
    if(map[row+1][col+direction]->isEmpty() && map[row+1][col+direction]->isValid())
    {
        cells.push_back( map[row+1][col+direction]);
    }
    //DownRight or DownLeft
    if(map[row-1][col+direction]->isEmpty() && map[row-1][col+direction]->isValid())
    {
        cells.push_back( map[row-1][col+direction]);
    }

    return cells;
}
