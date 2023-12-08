#ifndef STACKCOMMANDHISTORY_H
#define STACKCOMMANDHISTORY_H

#include "commandhistory.h"
#include "../actions/commandaction.h"

#include <memory>


class StackCommandHistory : public CommandHistory
{
private:
    std::stack<std::shared_ptr<CommandAction>> undoStack;
    std::stack<std::shared_ptr<CommandAction>> redoStack;

public:
    void push(std::shared_ptr<CommandAction> action) override {
        undoStack.push(action);
        while (!redoStack.empty())
            redoStack.pop();
    }

    void undo() override {
        if (!undoStack.empty()) {
            std::shared_ptr<CommandAction> lastAction = undoStack.top();
            lastAction->undo();
            undoStack.pop();
            redoStack.push(lastAction);
        }
    }

    void redo() override {
        if (!redoStack.empty()) {
            std::shared_ptr<CommandAction> nextAction = redoStack.top();
            nextAction->execute();
            redoStack.pop();
            undoStack.push(nextAction);
        }
    }
};


#endif // STACKCOMMANDHISTORY_H
