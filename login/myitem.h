#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>

class MyItem : public QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*e);

private:
    QColor color;
};

#endif // MYITEM_H
