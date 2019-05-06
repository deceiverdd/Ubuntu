#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qfiledialog.h>
#include <qtextstream.h>
#include <qdialog.h>
#include <QLineEdit>
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    init();

    this->FindFuncInit();
    this->StatusLabelInit();
    this->PermanentStatusLabelInit();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //ui->statusBar->showMessage(tr("左下角展示临时信息！"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
    statusLabel->setText(tr("(%1,%2)").arg(e->x()).arg(e->y()));
}

void MainWindow::FindFuncInit()
{
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("Find"));
    findLineEdit = new QLineEdit(findDlg);
    QPushButton *btn = new QPushButton(tr("find next one"),findDlg);
    QVBoxLayout *layout = new QVBoxLayout(findDlg);
    layout -> addWidget(findLineEdit);
    layout -> addWidget(btn);
    connect(btn,&QPushButton::clicked,this,&MainWindow::showFindText);
}

void MainWindow::StatusLabelInit()
{
    statusLabel = new QLabel;
    statusLabel->setMinimumSize(150,20);
    statusLabel->setFrameShape(QFrame::WinPanel);
    statusLabel->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(statusLabel);
    statusLabel->setText(tr("状态信息栏"));
}

void MainWindow::PermanentStatusLabelInit()
{
    QLabel *permanent = new QLabel;
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText(tr("<a href=\"http://www.baidu.com\">百度</a>"));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);
}

void MainWindow::init()
{
    isUnTitled = true;
    curFile = tr("未命名的.txt");
    setWindowTitle(curFile);

    ui->textEdit->clear();
    ui->textEdit->setVisible(true);
}

void MainWindow::timerEvent(QTimerEvent* e)
{
    if(e->timerId() == timer_1)
        statusLabel->setText(tr("timer1"));
     if(e->timerId() == timer_2)
         statusLabel->setText(tr("timer2"));
     if(e->timerId() == timer_3)
         statusLabel->setText(tr("timer3 %1").arg(qrand()%10));

}

void MainWindow::newFile()
{
    if(maybeSave())
    {
        init();
    }
}

bool MainWindow::maybeSave()
{
    //使用isModified()判断textEdit是否发生了更改
    if(ui->textEdit->document()->isModified())
    {
        //自定义警告对话框
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr("尚未保存，是否保存？"));

        QPushButton *yesBtn = box.addButton(tr("是(&Y)"),QMessageBox::YesRole);
        QPushButton *cancleBtn = box.addButton(tr("取消"),QMessageBox::RejectRole);
        box.addButton(tr("否(&N)"),QMessageBox::NoRole);

        //弹出对话框
        box.exec();

        if(box.clickedButton() == yesBtn)
        {
            //保存并返回true
            return save();
        }
        else if(box.clickedButton() == cancleBtn)
        {
            //不保存返回false
            return false;
        }
    }
    else
    {
        //当前文件未发生更改返回true
        return true;
    }
}

bool MainWindow::save()
{
    if(isUnTitled)
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),curFile);

    if(fileName.isEmpty())
    {
       return false;
    }

    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    //根据字符串fileName新建QFile类型的file
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器"),tr("无法写入文件 %1：/n %2").arg(fileName).arg(file.errorString()));

        return false;
    }

    //根据file新建文本流out
    QTextStream out(&file);

    //修改指针状态为等待
    QApplication::setOverrideCursor(Qt::WaitCursor);

    //将textEdit上的文本写入文本流
    out<<ui->textEdit->toPlainText();

    //恢复指针状态
    QApplication::restoreOverrideCursor();
    isUnTitled = false;

    //获得文件的标准路径
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

bool MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("多文档编辑器"),tr("无法写入文件 %1: /n %2").arg(fileName).arg(file.errorString()));

        return  false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_newFile_triggered()
{
    newFile();
}

void MainWindow::on_save_triggered()
{
    save();
}

void MainWindow::on_saveAs_triggered()
{
    saveAs();
}

void MainWindow::on_open_triggered()
{
    if(maybeSave())
    {
        QString fileName = QFileDialog::getOpenFileName(this);

        if(!fileName.isEmpty())
        {
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::showFindText()
{
    QString str = findLineEdit -> text();
    if(!ui->textEdit->find(str,QTextDocument::FindBackward))
    {
            QMessageBox::warning(this,tr("find"),tr("canot find %1").arg(str));
    }
}

void MainWindow::on_actionFind_triggered()
{
    findDlg->show();
}

void MainWindow::on_BtnTimer_clicked()
{
    //timer_1 = startTimer(3000);
    //timer_2 = startTimer(5000);
    //timer_3 = startTimer(2000);

    QTimer* timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&MainWindow::timerUpdate);
    timer->start();
}

void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    //QString str = time.toString(Qt::DateFormat::DefaultLocaleShortDate);
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    statusLabel->setText(str);
}

void MainWindow::on_BtnRandomPos_clicked()
{
    int rand = qrand()%300;
    statusLabel->setText(QString::number(rand));
}
