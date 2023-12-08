#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "command.h"
#include "../user_interface/itemrenderer.h"

class DisplayCommand: public Command
{
public:
    DisplayCommand(std::unordered_map<std::string, std::string> options);
    void execute() override;

private:
    void displayOneItem(const Slide&);
    void displayWholeSlide(const Slide&);

private:
    ItemRenderer itemRenderer;
};

#endif // DISPLAYCOMMAND_H
