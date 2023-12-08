#ifndef DRAGGABLEITEMHANDLER_H
#define DRAGGABLEITEMHANDLER_H

#include <QObject>
#include <QPoint>

class DraggableItemHandler : public QObject
{
    Q_OBJECT

public:
    DraggableItemHandler(QObject* parent = nullptr);
    void makeDraggable(QObject* item);

signals:
    void itemDragged(QObject* item, const QPoint& newPosition);

private slots:
    void handleDragStart(QObject* item, const QPoint& startPosition);
    void handleDragMove(QObject* item, const QPoint& newPosition);
    void handleDragEnd(QObject* item, const QPoint& endPosition);
};

#endif // DRAGGABLEITEMHANDLER_H
