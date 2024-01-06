#ifndef SHAPE_H
#define SHAPE_H

#include "../../PresentationElements/Item/item.h"

#include <QPen>
#include <QPainter>

#include <memory>

class Shape
{
public:
    virtual void draw(std::shared_ptr<Item>, QPainter&)=0;

};

#endif // SHAPE_H
