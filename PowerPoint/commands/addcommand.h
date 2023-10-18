#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"
#include "../factory/itembuilderfactory.h"
#include "../itembuilders/itembuilder.h"
#include "../itembuilders/itemdirector.h"
#include "../parser/lexer.h"

#include <memory>
#include <optional>
#include <string>
#include <vector>

class AddCommand: public Command
{
public:
    AddCommand()=default;
    void execute(Slide&) override;

public:
    ItemBuilderFactory item_builder_factory;
    ItemDirector item_director;
    static int id_count;
    Coord top_left, bottom_right;
    Item::Length width, height;
    std::string item_name;

};

#endif // ADDCOMMAND_H
