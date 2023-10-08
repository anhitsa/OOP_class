#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"
#include "../parser/lexer.h"

#include <memory>
#include <optional>
#include <string>
#include <vector>

class AddCommand: public Command
{
public:
    AddCommand()=default;
    AddCommand(Item::Coord top_left, Item::Coord bottom_right);
    AddCommand(Item::Coord top_left, Item::Length width, Item::Length height);
    void execute(Slide&) override;

public:
    Item item;
    static int id_count;
};

#endif // ADDCOMMAND_H
