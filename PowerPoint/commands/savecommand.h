#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "command.h"

#include <string>

class SaveCommand: public Command
{
public:
    SaveCommand()=default;
    void execute() override;

public:
    std::string path;

private:
    std::string determineItemBlockText(const Item&) const;

};

#endif // SAVECOMMAND_H
