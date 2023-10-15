#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H

#include "command.h"

class ChangeCommand: public Command
{
public:
    ChangeCommand() : item(std::make_unique<Item>()) {}
    void execute(Slide&) override;

public:
    std::unique_ptr<Item> item;
};

#endif // CHANGECOMMAND_H
