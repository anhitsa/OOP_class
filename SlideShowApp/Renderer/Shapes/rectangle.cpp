#include "rectangle.h"

void Rectangle::draw(std::shared_ptr<Item> item, QPainter& painter)
{
    const RectangleGeometry& geometry = item->getGeometry();
    painter.drawRect(QRect(item->getGeometry().getTopLeft().getX(), item->getGeometry().getTopLeft().getY(),item->getGeometry().getWidth(), item->getGeometry().getHeight()));
    painter.drawText(geometry.getTopLeft().getX(), geometry.getTopLeft().getY(), geometry.getWidth(), geometry.getHeight(),Qt::AlignCenter, QString::fromStdString(item->getText()));
}
