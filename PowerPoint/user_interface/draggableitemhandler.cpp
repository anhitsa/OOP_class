#include "DraggableItemHandler.h"

#include <QMouseEvent>

DraggableItemHandler::DraggableItemHandler(QObject* parent)
    : QObject(parent)
{
}

void DraggableItemHandler::makeDraggable(QObject* item)
{/*
    QObject::connect(item, &QObject::mousePressEvent, this, [this, item](QMouseEvent* event) {
        handleDragStart(item, event->pos());
    });

    QObject::connect(item, &QObject::mouseMoveEvent, this, [this, item](QMouseEvent* event) {
        if (event->buttons() & Qt::LeftButton) {
            handleDragMove(item, event->pos());
        }
    });

    QObject::connect(item, &QObject::mouseReleaseEvent, this, [this, item](QMouseEvent* event) {
        handleDragEnd(item, event->pos());
    });*/
}

void DraggableItemHandler::handleDragStart(QObject* item, const QPoint& startPosition)
{
}

void DraggableItemHandler::handleDragMove(QObject* item, const QPoint& newPosition)
{
    emit itemDragged(item, newPosition);
}

void DraggableItemHandler::handleDragEnd(QObject* item, const QPoint& endPosition)
{
}
