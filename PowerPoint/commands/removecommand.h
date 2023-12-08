#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"

class RemoveCommand: public Command
{
public:
    RemoveCommand()=default;
    void execute() override;

};

#endif // REMOVECOMMAND_H
