#include "line.h"

void Line::draw(std::shared_ptr<Item> item, QPainter& painter)
{
    const RectangleGeometry& geometry = item->getGeometry();
    painter.drawLine(item->getGeometry().getTopLeft().getX(), item->getGeometry().getTopLeft().getY(), item->getGeometry().getTopLeft().getX() + item->getGeometry().getWidth(), item->getGeometry().getTopLeft().getY() + item->getGeometry().getWidth());
}
