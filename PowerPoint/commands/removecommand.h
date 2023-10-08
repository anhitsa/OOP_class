#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"

class RemoveCommand: public Command
{
public:
    RemoveCommand()=default;
    void execute(Slide&) override {} // to be implemented

public:
    Item item;
};

#endif // REMOVECOMMAND_H
