#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "command.h"

#include <string>

class SaveCommand: public Command
{
public:
    SaveCommand(std::unordered_map<std::string, std::string> options);
    void execute() override;

public:
    std::string path;

private:
    std::string determineItemBlockText(const Item&) const;

};

#endif // SAVECOMMAND_H
