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
    void execute(Slide&) override;

public:
    std::unique_ptr<Item> item;
    static int id_count;
};

#endif // ADDCOMMAND_H
