#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"
#include "../../PresentationElements/document.h"
#include "../../PresentationElements/Item/item.h"
#include "../../ActionHandler/ActionManager/actionmanager.h"
#include "../../ActionHandler/Actions/removeitemaction.h"
#include "../../ActionHandler/Actions/removeslideaction.h"

class RemoveCommand: public Command
{
public:
    RemoveCommand(std::map<std::string, std::string> options, std::shared_ptr<Document>, std::shared_ptr<ActionManager>);
    void execute() override;

private:
    void removeSlide();
    void removeItem();

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<ActionManager> actionManager;

};

#endif // REMOVECOMMAND_H
