#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "startupmenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartupMenu startupMenu;

    startupMenu.show();

    return a.exec();
}
