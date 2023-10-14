#include "displaycommand.h"

void DisplayCommand::execute(Slide& slide)
{
    item = slide.getItemByID(item.id);
    itemDrawer.draw(item);
}

