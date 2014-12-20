#include "../include/Cpu.h"

Cpu::Cpu(string name, string color, bool home):
    Player(name, color, home)
{

}

Cpu::~Cpu()
{
    //dtor
}

bool Cpu::moverPieza()
{
    return false;
}

