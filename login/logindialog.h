#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_loginBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::LoginDialog *ui;
    void keyPressEvent(QKeyEvent*);//键盘事件
};

#endif // LOGINDIALOG_H
