#include "removecommand.h"

#include <algorithm>

void RemoveCommand::execute(Slide& slide)
{
    slide.items.erase(std::remove_if(slide.items.begin(), slide.items.end(),
                                     [this](const Item& slideItem) {
                                         return slideItem.id == id;
                                     }), slide.items.end());
    slide.update();
}
