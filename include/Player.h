#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Piece.h"

using std::string;
using std::vector;

class Player
{
    public:
        Player(string name, string color, bool home);
        virtual ~Player();
        //static const int MAX_PIEZAS = 10;
        virtual bool moverPieza() = 0;
        inline bool isHome(){return _home;}
        inline string getName() { return _name; }
        inline string getColor() { return _color; }
        Piece* findPieceAt(int row, int col);
        Piece* getRandomPiece();
        inline vector<Piece*> getPieces(){return _pieces;}
        inline void addPiece(Piece* piece)
        {
            _pieces[_counter] = piece;
            _counter++;
        }
    private:
        string _name;
        string _color;
        bool _home;
        vector<Piece*> _pieces;
        int _counter = 0;

};

#endif // PLAYER_H

