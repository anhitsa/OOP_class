#ifndef COMMANDACTION_H
#define COMMANDACTION_H


class CommandAction {
public:
    virtual ~CommandAction() = default;
    virtual void execute() = 0;
    virtual void undo() = 0; //TK: You do not need this methiod, only execute is enough
};

#endif // COMMANDACTION_H
