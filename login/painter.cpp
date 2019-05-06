#include "painter.h"
#include "ui_painter.h"
#include <qpainter.h>

Painter::Painter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Painter)
{
    ui->setupUi(this);
    setWindowTitle(tr("绘图"));
}

Painter::~Painter()
{
    delete ui;
}

void Painter::paintEvent(QPaintEvent*)
{
    //绘制线段
    QPainter painter(this);
    painter.drawLine(QPointF(0,0),QPointF(100,100));

    //设置画笔和笔刷绘制矩形
    QPen pen;
    pen.setColor(Qt::red);

    QBrush brush(Qt::Dense3Pattern);
    brush.setColor(QColor(0,255,0,100));

    painter.setPen(pen);
    painter.setBrush(brush);

    //painter.drawRect(0,0,50,50);

    //绘制弧形
    QRectF arcRect(10,10,100,100);
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    //painter.drawArc(arcRect,startAngle,spanAngle);

    //线性渐变
    QLinearGradient linearGradient(QPointF(0,0),QPointF(80,80));

    linearGradient.setColorAt(0,Qt::red);
    linearGradient.setColorAt(0.5,Qt::green);
    linearGradient.setColorAt(1,Qt::blue);

    linearGradient.setSpread(QGradient::RepeatSpread);
    painter.setBrush(linearGradient);
    //painter.drawRect(0,0,1000,1000);

    //辐射渐变
    //圆点 半径 焦点位置
    //焦点的位置为0，圆环的位置为1，然后在焦点和圆环间插入颜色。
    QRadialGradient radialGradient(QPointF(100,190),50,QPointF(275,200));
    radialGradient.setColorAt(0,Qt::white);
    radialGradient.setColorAt(1,Qt::black);

    radialGradient.setSpread(QGradient::RepeatSpread);
    painter.setBrush(radialGradient);
    //painter.drawEllipse(QPointF(100,200),1000,1000);

    //圆锥渐变
    //中心点 角度
    //沿逆时针从给定的角度开始环绕中心点插入颜色。这里给定的角度沿逆时针方向开始的位置为0，旋转一圈后为1
    QConicalGradient conicalGradient(QPointF(100,190),50);
    conicalGradient.setColorAt(0,Qt::white);
    conicalGradient.setColorAt(1,Qt::black);

    conicalGradient.setSpread(QGradient::RepeatSpread);
    painter.setBrush(conicalGradient);
    //painter.drawEllipse(QPointF(100,200),1000,1000);

    QFont font("楷体",20,QFont::Bold,false);
    font.setOverline(true);
    font.setUnderline(true);
    font.setCapitalization(QFont::SmallCaps);
    font.setLetterSpacing(QFont::AbsoluteSpacing,10);

    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(100,100,tr("painttext"));
}
