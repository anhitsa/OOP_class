#include "additemaction.h"

AddItemAction::AddItemAction(std::shared_ptr<Item> item, std::shared_ptr<Slide> slide)
    : item(item), slide(slide)
{

}

void AddItemAction::execute()
{
    slide->add(item);
}

void AddItemAction::undo()
{
    slide->remove(item);
}
