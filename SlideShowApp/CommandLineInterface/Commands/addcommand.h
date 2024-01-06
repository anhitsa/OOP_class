#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "command.h"
#include "../../PresentationElements/document.h"
#include "../../ActionHandler/Actions/additemaction.h"
#include "../../ActionHandler/Actions/addslideaction.h"
#include "../../ActionHandler/ActionManager/actionmanager.h"
#include "../../PresentationElements/document.h"
#include "../../PresentationElements/Item/item.h"

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
    void addItem();
    void addSlide();
    std::shared_ptr<Item> createItem(const Item::ID);

private:
    std::shared_ptr<Document> document;
    std::shared_ptr<ActionManager> actionManager;

};

#endif // ADDCOMMAND_H
