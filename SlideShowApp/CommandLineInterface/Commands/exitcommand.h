#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "command.h"
#include "../../Application/application.h"

#include <map>

class ExitCommand: public Command
{
public:
    ExitCommand(std::map<std::string, std::string> options_) { options = options_; }
    void execute() override;

};

#endif // EXITCOMMAND_H
