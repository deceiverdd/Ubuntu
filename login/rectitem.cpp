#include "rectitem.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QMimeData>
#include <QGraphicsSceneEvent>
#include <QVariant>
#include <qvariant.h>
#include <QVariantComparisonHelper>

RectItem::RectItem()
{
    setAcceptDrops(true);
    color = QColor(Qt::lightGray);
}

QRectF RectItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *,
                     QWidget *)
{
    //如果其上有拖动，颜色变亮
    painter->setBrush(dragOver ? color.light(130) : color);
    painter->drawRect(0,0,50,50);
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *e)
{
    if(e->mimeData()->hasColor())
    {
        e->setAccepted(true);
        dragOver = true;
        update();
    }
    else
        e->setAccepted(false);
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *e)
{
    Q_UNUSED(e);
    dragOver = false;
    update();
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *e)
{
    dragOver = false;

    if(e->mimeData()->hasColor())
        color = qvariant_cast<QColor>(e->mimeData()->colorData());

    update();
}
