#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"

class RemoveCommand: public Command
{
public:
    RemoveCommand()=default;
    void execute(Slide&) override;
public:
    int id;
};

#endif // REMOVECOMMAND_H
