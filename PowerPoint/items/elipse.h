#ifndef ELIPSE_H
#define ELIPSE_H

#include "item.h"

class Elipse : public Item
{
public:
    Elipse()=default;
    void draw() override;
};

#endif // ELIPSE_H
