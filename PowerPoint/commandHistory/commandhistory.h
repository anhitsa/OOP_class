#ifndef COMMANDHISTORY_H
#define COMMANDHISTORY_H

#include <memory>

class CommandHistory {
public:
    virtual ~CommandHistory() = default;
    virtual void push(std::shared_ptr<CommandAction> action) = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

#endif // COMMANDHISTORY_H
