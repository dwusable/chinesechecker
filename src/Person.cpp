#include "../include/Person.h"

Person::Person(string name, string color, bool home):
    Player(name, color, home)
{
    //ctor
}

Person::~Person()
{
    //dtor
}

bool Person::moverPieza()
{
    return false;
}

