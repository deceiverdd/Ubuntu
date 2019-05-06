#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>

namespace Ui {
class Painter;
}

class Painter : public QWidget
{
    Q_OBJECT

public:
    explicit Painter(QWidget *parent = nullptr);
    ~Painter();

protected:
    void paintEvent(QPaintEvent*);

private:
    Ui::Painter *ui;
};

#endif // PAINTER_H
