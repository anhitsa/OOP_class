#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"
#include "../../PresentationElements/document.h"
#include "../../Director/Actions/addaction.h"
#include "../../Director/ActionManager/actionmanager.h"
#include "../../PresentationElements/document.h"
#include "../../PresentationElements/Item/item.h"
#include "../../PresentationElements/Item/rectangle.h"

#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

class AddCommand: public Command
{
public:
    AddCommand(std::map<std::string, std::string> options_, std::shared_ptr<Document>, std::shared_ptr<ActionManager>);
    void execute() override;

private:
    std::shared_ptr<Target> createTarget();
    std::shared_ptr<Container<Target>> determineContainer(const std::shared_ptr<Target>&);
    std::shared_ptr<Target> createItem();

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<ActionManager> actionManager;
    std::shared_ptr<Target> target;
    std::shared_ptr<Container<Target>> container;
    static int slideIdCount;
    static int itemIdCount;

};

#endif // ADDCOMMAND_H
