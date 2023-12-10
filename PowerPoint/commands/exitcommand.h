#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "command.h"
#include "../user_interface/application_window.h"

#include <map>

class ExitCommand: public Command
{
public:
    ExitCommand(std::map<std::string, std::string> options);
    void execute() override;

private:
    std::map<std::string, std::string> options;

};


#endif // EXITCOMMAND_H
