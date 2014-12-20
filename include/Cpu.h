#ifndef CPU_H
#define CPU_H

#include "Player.h"

class Cpu : public Player
{
    public:
        Cpu(string name, string color, bool home);
        virtual ~Cpu();
        bool moverPieza();
    protected:
    private:
};

#endif // CPU_H

