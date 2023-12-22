#include "changeaction.h"

ChangeAction::ChangeAction(std::shared_ptr<Item> item, std::map<std::string, std::string> options)
    : item(item), options(options)
{

}

void ChangeAction::execute()
{
    auto itemGeometry = item->getGeometry();
    itemGeometry.changeParameters(options);
    item->setGeometry(itemGeometry);
}

void ChangeAction::undo()
{
    item->getGeometry().revertToLatestParameters();
}
