#ifndef COMMANDHISTORY_H
#define COMMANDHISTORY_H

#include "../actions/commandaction.h"

#include <memory>
#include <stack>

class CommandHistory {
public:
    static CommandHistory& getInstance();
    void push(std::shared_ptr<CommandAction> action);
    void undo();
    void redo();

private:
    std::stack<std::shared_ptr<CommandAction>> undoStack;
    std::stack<std::shared_ptr<CommandAction>> redoStack;

    CommandHistory() = default;
    CommandHistory(const CommandHistory&) = delete;
    CommandHistory& operator=(const CommandHistory&) = delete;

};

#endif // COMMANDHISTORY_H
