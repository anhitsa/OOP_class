#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "command.h"

class DisplayCommand: public Command
{
public:
    DisplayCommand()=default;
    void execute(Slide&) override {} // to be implemented

public:
    Item item;
};

#endif // DISPLAYCOMMAND_H
