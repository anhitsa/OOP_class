#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"

class RemoveCommand: public Command
{
public:
    RemoveCommand() : item(std::make_unique<Item>()) {}
    void execute(Slide&) override;

public:
    std::unique_ptr<Item> item;
};

#endif // REMOVECOMMAND_H
