#include "line.h"
#include "../user_interface/application_window.h"

#include <QPainter>

void Line::draw()
{
    appWindow.pixmap = QPixmap(appWindow.size());
    appWindow.pixmap.fill(Qt::white);

    QPainter painter(&appWindow.pixmap);

    painter.setBrush(Qt::DiagCrossPattern);
    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(5);
    painter.setPen(pen);

    painter.drawLine(top_left.x, top_left.y, top_left.x + width, top_left.y + width);

    painter.end();

    appWindow.imageLabel->setPixmap(appWindow.pixmap.scaled(appWindow.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    appWindow.imageLabel->show();
}
