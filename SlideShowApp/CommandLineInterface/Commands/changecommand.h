#ifndef CHANGECOMMAND_H
#define CHANGECOMMAND_H

#include "command.h"
#include "../../Director/Actions/changeaction.h"
#include "../../Director/ActionManager/actionmanager.h"
#include "../../PresentationElements/document.h"

class ChangeCommand: public Command
{
public:
    ChangeCommand(std::map<std::string, std::string> options, std::shared_ptr<Document>, std::shared_ptr<ActionManager>);
    void execute() override;
    std::shared_ptr<Item> determineItem();

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<ActionManager> actionManager;

};

#endif // CHANGECOMMAND_H
