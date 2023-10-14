#ifndef ITEMDRAWER_H
#define ITEMDRAWER_H

#include "../items/item.h"

class ItemDrawer
{
public:
    ItemDrawer()=default;
    void draw(const Item&);
};

#endif // ITEMDRAWER_H
