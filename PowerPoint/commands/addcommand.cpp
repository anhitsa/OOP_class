#include "addcommand.h"

int AddCommand::id_count = 0;

AddCommand::AddCommand(Item::Coord top_left, Item::Coord bottom_right)
{
    item = Item(top_left, bottom_right);
}

AddCommand::AddCommand(Item::Coord top_left, Item::Length height, Item::Length width)
{
    item = Item(top_left, height, width);
}

void AddCommand::execute(Slide& slide)
{
    id_count++;
    item.setID(id_count);
    slide.items.push_back(item);
}


