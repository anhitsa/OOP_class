#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H

#include "command.h"
#include "../items/item.h"

class ChangeCommand: public Command
{
public:
    ChangeCommand()=default;
    void execute() override;

};

#endif // CHANGECOMMAND_H
