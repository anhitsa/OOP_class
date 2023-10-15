#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "command.h"

class DisplayCommand: public Command
{
public:
    DisplayCommand() : item(std::make_unique<Item>()) {}
    void execute(Slide&) override;

public:
    std::unique_ptr<Item> item;
};

#endif // DISPLAYCOMMAND_H
