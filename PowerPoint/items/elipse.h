#ifndef ELIPSE_H
#define ELIPSE_H

#include "item.h"

class Elipse : public Item
{
public:
    Elipse()
    {
        top_left.x = bottom_right.x = top_left.y = bottom_right.y = 0;
        width = height = 1;
        id = 0;
    }
};

#endif // ELIPSE_H
