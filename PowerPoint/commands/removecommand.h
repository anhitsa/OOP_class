#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"

#include <map>

class RemoveCommand: public Command
{
public:
    RemoveCommand(std::map<std::string, std::string> options);
    void execute() override;

private:
    std::map<std::string, std::string> options;

};

#endif // REMOVECOMMAND_H
