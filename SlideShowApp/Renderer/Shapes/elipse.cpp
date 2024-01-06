#include "elipse.h"

void Elipse::draw(std::shared_ptr<Item> item, QPainter& painter)
{
    const RectangleGeometry& geometry = item->getGeometry();
    painter.drawEllipse(geometry.getTopLeft().getX(), geometry.getTopLeft().getY(), geometry.getWidth(), geometry.getHeight());
    painter.drawText(geometry.getTopLeft().getX(), geometry.getTopLeft().getY(), geometry.getWidth(), geometry.getHeight(), Qt::AlignCenter, QString::fromStdString(item->getText()));
}

