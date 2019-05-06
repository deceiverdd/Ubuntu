#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class QLineEdit;
class QDialog;
class QLabel;

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void newFile();//新建文件
    bool maybeSave();//判断是否需要保存
    bool save();//保存文件
    bool saveAs();//另存文件
    bool saveFile(const QString &fileName);//保存文件
    bool loadFile(const QString &fileName);//加载文件

private slots:

    void on_newFile_triggered();

    void on_save_triggered();

    void on_saveAs_triggered();

    void on_open_triggered();

    void showFindText();

    void on_actionFind_triggered();

    void on_BtnTimer_clicked();

    void timerUpdate();

    void on_BtnRandomPos_clicked();

private:
    Ui::MainWindow *ui;

    bool isUnTitled;//是否保存过
    QString curFile;

    int timer_1,timer_2,timer_3;

    void init();//初始化
    void FindFuncInit();//初始化查找控件
    void StatusLabelInit();//初始化状态信息栏
    void PermanentStatusLabelInit();//永久信息栏
    void mousePressEvent(QMouseEvent*);//鼠标事件
    void timerEvent(QTimerEvent*);//计时器事件


    QLineEdit *findLineEdit;
    QDialog *findDlg;
    QLabel *statusLabel;
    QLabel *permanentStatusLabel;
};

#endif // MAINWINDOW_H
