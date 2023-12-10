#include "commandhistory.h"

CommandHistory& CommandHistory::getInstance()
{
    static CommandHistory instance;
    return instance;
}

void CommandHistory::push(std::shared_ptr<CommandAction> action)
{
    undoStack.push(action);
    while (!redoStack.empty())
        redoStack.pop();
}

void CommandHistory::undo()
{
    if (!undoStack.empty())
    {
        std::shared_ptr<CommandAction> lastAction = undoStack.top();
        lastAction->undo();
        undoStack.pop();
        redoStack.push(lastAction);
    }
}

void CommandHistory::redo()
{
    if (!redoStack.empty())
    {
        std::shared_ptr<CommandAction> nextAction = redoStack.top();
        nextAction->execute();
        redoStack.pop();
        undoStack.push(nextAction);
    }
}
