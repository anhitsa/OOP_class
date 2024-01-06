#include "circle.h"

void Circle::draw(std::shared_ptr<Item> item, QPainter& painter)
{
    const RectangleGeometry& geometry = item->getGeometry();
    painter.drawEllipse(geometry.getTopLeft().getX(), geometry.getTopLeft().getY(), geometry.getWidth(), geometry.getWidth());
    painter.drawText(geometry.getTopLeft().getX(), geometry.getTopLeft().getY(), geometry.getWidth(), geometry.getWidth(),Qt::AlignCenter, QString::fromStdString(item->getText()));
}
