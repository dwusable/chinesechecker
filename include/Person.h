#ifndef PERSON_H
#define PERSON_H

#include "Player.h"


class Person : public Player
{
    public:
        Person(string name, string color, bool home);
        virtual ~Person();
        bool moverPieza();
    protected:
    private:
};

#endif // PERSON_H

