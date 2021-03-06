#include "myitem.h"
#include <QCursor>
#include <qpainter.h>
#include <QTime>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QWidget>
#include <QMimeData>
#include <QPixmap>

MyItem::MyItem() : QGraphicsItem ()
{
    setToolTip("Click and drag me!");  //提示
    setCursor(Qt::OpenHandCursor);    //改变光标形状

//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    color = QColor(qrand()%256,qrand()%256,qrand()%256);
}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void MyItem::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);
    painter->setBrush(color);
    painter->drawRect(0,0,20,20);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
    if(e->button() != Qt::LeftButton)
    {
        //如果不是鼠标左键按下，则忽略该事件
        e->ignore();
        return;
    }

    setCursor(Qt::ClosedHandCursor);
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent* e)
{
    if(QLineF(e->screenPos(),e->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())
    {
        //如果按下的点到现在的点的距离小于程序默认的拖动距离，表明没有拖动，则返回
        return;
    }

    //为event所在窗口部件新建拖动对象
    QDrag *drag = new QDrag(e->widget());

    //新建QMimeData对象，用来存储拖动的数据
    QMimeData *mimeData = new QMimeData;

    drag->setMimeData(mimeData);

    mimeData->setColorData(color);

    //新建QPixmap对象，它用来重新绘制圆形，在拖动时显示
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    paint(&painter,0,0);
    drag->setPixmap(pixmap);

    //我们让指针指向圆形的(10,15)点
    drag->setHotSpot(QPoint(10, 15));
    //开始拖动
    drag->exec();
    //改变光标形状
    setCursor(Qt::OpenHandCursor);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* e)
{
    setCursor(Qt::OpenHandCursor);    //改变光标形状
}
