#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "command.h"

class DisplayCommand: public Command
{
public:
    DisplayCommand()=default;
    void execute(Slide&) override;

public:
    int id;

private:
    void displayOneItem(const Slide&);
    void displayWholeSlide(const Slide&);
};

#endif // DISPLAYCOMMAND_H
