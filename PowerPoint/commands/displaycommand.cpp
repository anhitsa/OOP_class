#include "displaycommand.h"

void DisplayCommand::execute(Slide& slide)
{
    for(auto& item_: slide.items)
    {
        if(item_->id == item->id)
            item_->draw();
    }
}
