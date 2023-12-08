#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H

#include "command.h"

class ChangeCommand: public Command
{
public:
    ChangeCommand(std::unordered_map<std::string, std::string> options);
    void execute() override;

};

#endif // CHANGECOMMAND_H
