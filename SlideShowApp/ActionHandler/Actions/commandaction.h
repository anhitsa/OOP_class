#ifndef COMMANDACTION_H
#define COMMANDACTION_H

class CommandAction
{
public:
    virtual ~CommandAction()=default;
    virtual void execute()=0;
    virtual void undo()=0;

};

#endif // COMMANDACTION_H
