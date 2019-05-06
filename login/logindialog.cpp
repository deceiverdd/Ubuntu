#include "logindialog.h"
#include "ui_logindialog.h"
#include <qmessagebox.h>
#include <QKeyEvent>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("登录框"));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text().trimmed() == tr("dongdi") && ui->pwdLineEdit->text() == tr("123456"))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,tr("警告"),tr("用户名或者密码错误！"),QMessageBox::Ok);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }

}

void LoginDialog::keyPressEvent(QKeyEvent* e)
{
    int x = ui->loginBtn->x();
    int y = ui->loginBtn->y();

    switch (e->key())
    {
        case Qt::Key_Up:ui->loginBtn->move(x,y-10);break;
        case Qt::Key_Down:ui->loginBtn->move(x,y+10);break;
        case Qt::Key_Left:ui->loginBtn->move(x-10,y);break;
        case Qt::Key_Right:ui->loginBtn->move(x+10,y);break;
    }
}

void LoginDialog::on_exitBtn_clicked()
{
    close();
}
