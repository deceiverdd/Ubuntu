#ifndef GVFRAMEWORK_H
#define GVFRAMEWORK_H

#include <QWidget>
#include <qgraphicsscene.h>

namespace Ui {
class GVFramework;
}

class GVFramework : public QWidget
{
    Q_OBJECT

public:
    explicit GVFramework(QWidget *parent = nullptr);
    ~GVFramework();
    void ShowRect();

private:
    Ui::GVFramework *ui;
};

#endif // GVFRAMEWORK_H
