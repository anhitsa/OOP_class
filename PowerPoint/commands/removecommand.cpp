#include "removecommand.h"

#include <algorithm>

void RemoveCommand::execute(Slide& slide)
{
    for(auto& slideItem : slide.items)
    {
        if(slideItem->id == id)
            slide.items.erase(std::remove(slide.items.begin(), slide.items.end(), slideItem), slide.items.end());
    }
}
