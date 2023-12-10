#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "command.h"

#include <map>
#include <string>

class SaveCommand: public Command
{
public:
    SaveCommand(std::map<std::string, std::string> options);
    void execute() override;

public:
    std::string path;

private:
    std::map<std::string, std::string> options;

//private:
//    std::string determineItemBlockText(const Item&) const;

};

#endif // SAVECOMMAND_H
