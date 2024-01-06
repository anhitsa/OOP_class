#include "removeitemaction.h"

RemoveItemAction::RemoveItemAction(std::shared_ptr<Item> item, std::shared_ptr<Slide> slide) : item(item), slide(slide)
{

}

void RemoveItemAction::execute()
{
    slide->remove(item);
}

void RemoveItemAction::undo()
{
    slide->add(item);
}
