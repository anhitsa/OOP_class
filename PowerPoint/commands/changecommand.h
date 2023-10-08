#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H

#include "command.h"

class ChangeCommand: public Command
{
public:
    ChangeCommand()=default;
    void execute(Slide&) override;

public:
    Item item;
};

#endif // CHANGECOMMAND_H
