#include "circle.h"
#include "../user_interface/application_window.h"

#include <QPainter>

void Circle::draw()
{
    QPainter painter(&appWindow.pixmap);

    painter.setBrush(Qt::DiagCrossPattern);
    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(5);
    painter.setPen(pen);

    painter.drawEllipse(top_left.x, top_left.y, width, height);

    painter.end();

    appWindow.imageLabel->setPixmap(appWindow.pixmap.scaled(appWindow.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    appWindow.imageLabel->show();
}
