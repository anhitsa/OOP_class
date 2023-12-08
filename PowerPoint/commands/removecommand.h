#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"

class RemoveCommand: public Command
{
public:
    RemoveCommand(std::unordered_map<std::string, std::string> options);
    void execute() override;

};

#endif // REMOVECOMMAND_H
