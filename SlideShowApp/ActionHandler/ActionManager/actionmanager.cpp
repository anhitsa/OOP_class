#include "actionmanager.h"

void ActionManager::do_(std::shared_ptr<CommandAction> action)
{
    action->execute();
    undoStack.push(action);

    while (!redoStack.empty())
        redoStack.pop();
}

void ActionManager::undo()
{
    if (!undoStack.empty())
    {
        std::shared_ptr<CommandAction> lastAction = undoStack.top();
        lastAction->undo();
        undoStack.pop();
        redoStack.push(lastAction);
    }
}

void ActionManager::redo()
{
    if (!redoStack.empty())
    {
        std::shared_ptr<CommandAction> nextAction = redoStack.top();
        nextAction->execute();
        redoStack.pop();
        undoStack.push(nextAction);
    }
}
