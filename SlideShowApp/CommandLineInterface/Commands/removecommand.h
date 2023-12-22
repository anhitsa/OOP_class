#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "command.h"
#include "../../PresentationElements/document.h"
#include "../../PresentationElements/Item/item.h"
#include "../../Director/ActionManager/actionmanager.h"
#include "../../Director/Actions/removeaction.h"

class RemoveCommand: public Command
{
public:
    RemoveCommand(std::map<std::string, std::string> options, std::shared_ptr<Document>, std::shared_ptr<ActionManager>);
    void execute() override;

private:
    std::shared_ptr<Target> determineTarget();
    std::shared_ptr<Container<Target>> determineContainer(const std::shared_ptr<Target>&);

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<ActionManager> actionManager;

};

#endif // REMOVECOMMAND_H
