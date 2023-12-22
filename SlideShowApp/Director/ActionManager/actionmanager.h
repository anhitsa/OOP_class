#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include "../Actions/commandaction.h"

#include <memory>
#include <stack>

class ActionManager
{
public:
    ActionManager() = default;
    void do_(std::shared_ptr<CommandAction> action);
    void undo();
    void redo();

private:
    std::stack<std::shared_ptr<CommandAction>> undoStack;
    std::stack<std::shared_ptr<CommandAction>> redoStack;

};

#endif // ACTIONMANAGER_H
