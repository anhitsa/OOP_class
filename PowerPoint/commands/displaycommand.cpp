#include "displaycommand.h"

void DisplayCommand::execute(Slide& slide)
{
    if(id)
        displayOneItem(slide);
    else
        displayWholeSlide(slide);
}

void DisplayCommand::displayOneItem(const Slide& slide)
{
    for(auto& item: slide.items)
    {
        if(item.id == id)
            itemRenderer.drawItem(item);
    }
}

void DisplayCommand::displayWholeSlide(const Slide& slide)
{
    for(auto& item: slide.items)
        itemRenderer.drawItem(item);
}
