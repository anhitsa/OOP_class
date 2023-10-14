#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "command.h"
#include "../user_interface/mainwindow.h"

class ExitCommand: public Command
{
public:
    ExitCommand()=default;
    void execute(Slide&) override;

};


#endif // EXITCOMMAND_H
