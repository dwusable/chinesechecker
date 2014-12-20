#include "../include/Match.h"

Match::~Match()
{
    //dtor
}

Match::Match(vector<Player*> players, Board* board): _players(players),
_board(board)
{
    init();
    //time(&_horaInicio);
}

void Match::init()
{
    _actualPlayer = _players[0];
    //testing actualPlayer
    //cout <<"Actual Player " << _actualPlayer->getName() << endl;
}

string Match::getInformacionJugadores()
{
    string infoJugadores = "*********Jugadores********* \n";

    for(Player* player : _players )
    {
        infoJugadores += player->getName() + "\n";
    }

    return infoJugadores;
}

void Match::assignPieces()
{
    //Refactoring, this is not flexible
    //1st Player
    Piece* piece;
    //int counter = 0;
    for(int i=0; i<4; i++){
        for(int j=4; j<8; j++){
            if(_board->map[i][j]->isValid()){
                //cout<< counter+1 << " -- ";
                piece = new Piece(_players[0]->getColor());
                piece->setCell(_board->map[i][j]);
                piece->getCell()->setPiece(piece);
                _players[0]->addPiece(piece);
                //counter++;
            }
        }
    }
    //2nd Player
    for(int i=13; i<17; i++)
    {
        for(int j=4; j<8; j++)
        {
            if(_board->map[i][j]->isValid())
            {
                piece = new Piece(_players[1]->getColor());
                piece->setCell(_board->map[i][j]);
                piece->getCell()->setPiece(piece);
                _players[1]->addPiece(piece);
            }
        }
    }
}

void Match::movePiece(Piece* piece, Cell* destination)
{
    //actualPlayer->
    //if(_actualPlayer)
    piece->getCell()->clean();
    piece->setCell(destination);
    destination->setPiece(piece);
    if(_count == _players.size()-1)
    {
        _count=0;
    }
    else
    {
        _count++;
    }
    _actualPlayer = _players[_count];
}

vector<Cell*> Match::getPiecePossibleMoves(int row, int col)
{
    vector<Cell*> moves;
    Piece* piece;
    piece = _actualPlayer->findPieceAt(row, col);
    if(piece != nullptr)
    {
        moves = _board->getPossibleMoves(piece->getCell());
    }
    else
    {
        cout << "No found" << endl;
    }
    /*int row = prow - 1;
    int col = pcol - 1;
    vector< vector<int> > possibleMovesList(30, vector<int>(30));
    Piece* selectedPiece = _board->map[row][col]->getPiece();
    string result = "";

    if(selectedPiece == nullptr){
        result = "Ninguna pieza en las posiciones ingresadas";
    }else{
        getPossibleRightMoves(possibleMovesList, row, col);
    }
    */
    return moves;
}

/*const Player* Match::getJugadorAt(int pindice) const
{
    if(pindice <= MAX_JUGADORES){
        return &_listaJugadores[pindice];
    }
}
*/
/*void Match::setHoraFin()
{
    if(_horaFin == 0){
        time(&_horaFin);
    }
}*/
