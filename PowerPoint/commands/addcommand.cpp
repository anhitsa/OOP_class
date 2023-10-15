#include "addcommand.h"

int AddCommand::id_count = 0;

void AddCommand::execute(Slide& slide)
{
    id_count++;
    item->id = id_count;
    slide.items.push_back(std::move(item));
}


