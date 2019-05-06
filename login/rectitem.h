#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsItem>

class RectItem : public QGraphicsItem
{
public:
    RectItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
protected:
     void dragEnterEvent(QGraphicsSceneDragDropEvent *e);
     void dragLeaveEvent(QGraphicsSceneDragDropEvent *e);
     void dropEvent(QGraphicsSceneDragDropEvent *e);
private:
     QColor color;
     bool dragOver;  //标志是否有拖动进入
};

#endif // RECTITEM_H
