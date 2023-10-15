#include "changecommand.h"

void ChangeCommand::execute(Slide& slide)
{
    for(auto& item_ : slide.items)
    {
        if(item_->id == item->id)
        {
            item_ = std::move(item);
            return;
        }
    }
}
