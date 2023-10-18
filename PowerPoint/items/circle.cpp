#include "circle.h"
#include "../user_interface/application_window.h"

#include <QMessageBox>
#include <QPainter>

void Circle::draw()
{
    QPainter painter(&appWindow.pixmap);

    painter.setBrush(Qt::Dense7Pattern);
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(5);
    painter.setPen(pen);

    painter.drawEllipse(top_left.x, top_left.y, width, width);

    painter.end();

    appWindow.imageLabel->setPixmap(appWindow.pixmap.scaled(appWindow.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    appWindow.imageLabel->show();
}
