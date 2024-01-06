#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include "../Actions/commandaction.h"

#include <memory>
#include <stack>

#include <QObject>

class ActionManager : public QObject
{
    Q_OBJECT

public:
    ActionManager()=default;
    void do_(std::shared_ptr<CommandAction> action);

public slots:
    void undo();
    void redo();

private:
    std::stack<std::shared_ptr<CommandAction>> undoStack;
    std::stack<std::shared_ptr<CommandAction>> redoStack;

};

#endif // ACTIONMANAGER_H
