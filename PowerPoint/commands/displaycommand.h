#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "command.h"
#include "../user_interface/itemdrawer.h"

class DisplayCommand: public Command
{
public:
    DisplayCommand()=default;
    void execute(Slide&) override;

public:
    Item item;
    ItemDrawer itemDrawer;
};

#endif // DISPLAYCOMMAND_H
