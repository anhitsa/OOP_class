#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "command.h"

class ExitCommand: public Command
{
public:
    ExitCommand()=default;
    void execute(Slide&) override {} // to be implemented

public:
    Item item;
};


#endif // EXITCOMMAND_H
