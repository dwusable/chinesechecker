#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Cell.h"
using std::vector;
class Board
{
    public:
        Board(int numPlayers);
        virtual ~Board();
        //static int MAP[ROWS][COLUMNS];
        Cell* map[17][13];
        vector<Cell*> getPossibleMoves(Cell* from);
    private:
        int _numPlayers;
        void fillMap();
        void createMap();
        //Direction 1 right, -1 left
        vector<Cell*> availableCell(int row, int col, int direction);

};

#endif // BOARD_H

