#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include <ctime>
#include "Player.h"
#include "Board.h"

using std::vector;

class Match
{

    public:
        Match(vector<Player*> players, Board* board);
        virtual ~Match();
        static const int MAX_JUGADORES = 6;
        inline const Board* getBoard() const { return _board; }
        inline void setBoard(Board* pboard) { _board = pboard; }
        inline vector<Player*> getPlayers(){return _players;}
        inline Player* getActualPlayer(){return _actualPlayer;}
        void movePiece(Piece* piece, Cell* destination);

        vector<Cell*> getPiecePossibleMoves(int row, int col);
        string getInformacionJugadores();
        void assignPieces();

    private:
        vector<Player*> _players;
        Player* _actualPlayer;
        Board* _board;
        int _count = 0;
        void init();
        //time_t _horaInicio;
        //time_t _horaFin;
};

#endif // MATCH_H

