#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H

#include "command.h"
#include "../document/target.h"

#include <map>

class ChangeCommand: public Command
{
public:
    ChangeCommand(std::map<std::string, std::string> options);
    void execute() override;
    std::shared_ptr<Target> determineTarget();

private:
    std::map<std::string, std::string> options; //TK: duplication

};

#endif // CHANGECOMMAND_H
