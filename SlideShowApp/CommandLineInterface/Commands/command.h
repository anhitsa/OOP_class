#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;

protected:
    std::map<std::string, std::string> options;

};

#endif // COMMAND_H
