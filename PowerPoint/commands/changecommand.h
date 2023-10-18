#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H

#include "command.h"
#include "../items/item.h"

class ChangeCommand: public Command
{
public:
    ChangeCommand()=default;
    void execute(Slide&) override;

public:
    Coord top_left, bottom_right;
    Item::Length width, height;
    int id;
};

#endif // CHANGECOMMAND_H
