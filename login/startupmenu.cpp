#include "startupmenu.h"
#include "ui_startupmenu.h"
#include "logindialog.h"
#include "mainwindow.h"

StartupMenu::StartupMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartupMenu)
{
    ui->setupUi(this);
    setWindowTitle(tr("QT Menu"));
}

StartupMenu::~StartupMenu()
{
    delete ui;
}

void StartupMenu::on_BtnTextEditor_clicked()
{
    //this->close();

    if(StartupMenu::textEditorLoginDialog.exec() == QDialog::Accepted)
    {
        StartupMenu::textEditorMainwindow.show();
    }
}

void StartupMenu::on_BtnDrawPic_clicked()
{
    StartupMenu::painterWindow.show();
}

void StartupMenu::on_BtnGVFramework_clicked()
{
    StartupMenu::gvFramwork.ShowRect();
}
