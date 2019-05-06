#ifndef STARTUPMENU_H
#define STARTUPMENU_H

#include <QDialog>
#include "logindialog.h"
#include "mainwindow.h"
#include "painter.h"
#include "gvframework.h"

namespace Ui {
class StartupMenu;
}

class StartupMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartupMenu(QWidget *parent = nullptr);
    ~StartupMenu();

private slots:
    void on_BtnTextEditor_clicked();

    void on_BtnDrawPic_clicked();

    void on_BtnGVFramework_clicked();

private:
    Ui::StartupMenu *ui;
    LoginDialog textEditorLoginDialog;
    MainWindow textEditorMainwindow;
    Painter painterWindow;
    GVFramework gvFramwork;
};

#endif // STARTUPMENU_H
