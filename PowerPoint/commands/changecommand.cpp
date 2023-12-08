#include "changecommand.h"

void ChangeCommand::execute()
{
    for(auto& item : slide.items)
    {
        if(item.id == id)
        {
            if(top_left)
                item.top_left = top_left;
            if(bottom_right)
                item.bottom_right = bottom_right;
            if(height)
                item.height = height;
            if(width)
                item.width = width;
            slide.update();
            return;
        }
    }
}
