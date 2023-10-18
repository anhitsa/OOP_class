#include "rectangle.h"
#include "../user_interface/application_window.h"

#include <QPainter>

void Rectangle::draw()
{
    QPainter painter(&appWindow.pixmap);

    painter.setBrush(Qt::Dense7Pattern);
    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidth(5);
    painter.setPen(pen);

    painter.drawRect(QRect(top_left.x, top_left.y, width, height));

    painter.end();

    appWindow.imageLabel->setPixmap(appWindow.pixmap.scaled(appWindow.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    appWindow.imageLabel->show();
}
