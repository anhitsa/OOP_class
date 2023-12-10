#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "command.h"
#include "../serializer/serializer.h"

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
    Serializer serializer;

};

#endif // SAVECOMMAND_H
