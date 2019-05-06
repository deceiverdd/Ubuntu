#include "gvframework.h"
#include "ui_gvframework.h"
#include <qgraphicsscene.h>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <myitem.h>
#include <rectitem.h>
#include <QDateTime>

GVFramework::GVFramework(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GVFramework)
{
    ui->setupUi(this);
    setWindowTitle("GVFramework");
}

GVFramework::~GVFramework()
{
    delete ui;
}

void GVFramework::ShowRect()
{
    // 场景
    QGraphicsScene *scene = new QGraphicsScene;

    //普通矩形
    //QGraphicsRectItem *item = new QGraphicsRectItem(100,100,50,50);

    //自定义类型
    //MyItem *item = new MyItem;
    //scene->addItem(item);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < 5; i++)
    {
        MyItem *item = new MyItem;
        item->setPos(i*50 +20,100);
        scene->addItem(item);
    }

    RectItem *rectItem = new RectItem;
    rectItem->setPos(100,200);
    scene->addItem(rectItem);

    QGraphicsView *view = new QGraphicsView;
    view->resize(400,300);

    view->setScene(scene);

    view->show();
}
