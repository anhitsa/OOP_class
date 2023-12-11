#ifndef COMMANDHISTORY_H
#define COMMANDHISTORY_H

#include "../actions/commandaction.h"

#include <memory>
#include <stack>

//TK: This is you ActionManager, call it respectively
class CommandHistory {
public:
    static CommandHistory& getInstance();
    //TK: this method should be called do() to be homohen pous with undo & redo
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
