#ifndef COMMAND_H
#define COMMAND_H

//TK: Coomand could be abstract base class, options and related methods could be common for all commands 
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif // COMMAND_H
