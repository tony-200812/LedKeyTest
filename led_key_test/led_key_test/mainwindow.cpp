#include "mainwindow.h"
#include "pannel.h"
#include "led.h"
#include <QString>
#include <QLabel>
#include <QFont>
#include <QColor>
#include <QLineEdit>

struct _rect {
    int x;
    int y;
    int h;
};

const struct _rect rectt[16] ={
    {20, 50,   40},
    {20, 100,  40},
    {20, 150,  40},
    {20, 200,  40},
    {20, 250,  40},
    {20, 300,  40},
    {20, 350,  40},
    {220, 50,  40},
    {220, 100, 40},
    {220, 150, 40},
    {220, 200, 40},
    {220, 250, 40},
    {220, 300, 40},
    {220, 350, 40},
    {420, 50,  110},
    {420, 190, 200},
};

struct _str_led {
    int x;
    int y;
    QString s;
    int key_no;
    QColor c;
};
const struct _str_led strr[] = {
    {70, 60,   "火    警", 1, Qt::red},
    {70, 110,  "启    动", 1, Qt::red},
    {70, 160,  "反    馈", 1, Qt::red},
    {70, 210,  "延    时", 1, Qt::red},
    {70, 260,  "故    障", 1, Qt::yellow},
    {70, 310,  "屏    蔽", 1, Qt::yellow},
    {70, 360,  "消    音", 1, Qt::green},

    {270, 60,  "监    管", 1, Qt::red},
    {270, 110, "系统故障", 1, Qt::yellow},
    {270, 160, "主电运行", 1, Qt::green},
    {270, 210, "备点运行", 1, Qt::green},
    {270, 260, "自动允许", 1, Qt::green},
    {270, 310, "手动允许", 1, Qt::green},
    {270, 360, "打印允许", 1, Qt::green},

    {450, 100, "请求/延时", 1, Qt::red},
    {450, 130, "启动", 1, Qt::red},
    {540, 100, "允许", 1, Qt::green},
    {540, 130, "喷洒", 1, Qt::red},
    {450, 250, "发送", 1, Qt::red},
    {450, 300, "屏蔽", 1, Qt::yellow},
    {450, 350, "故障", 1, Qt::yellow},
    {540, 250, "启动", 1, Qt::red},
    {540, 300, "屏蔽", 1, Qt::yellow},
    {540, 350, "故障", 1, Qt::yellow},
    {480, 70, "气体灭火", 1, Qt::red},
    {430, 200, "火警传输", 1, Qt::red},
    {520, 200, "声光报警", 1, Qt::yellow},
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    pannel *p;
    QLabel *l;
    led *ledd;

    this->setFixedSize(600, 550);

    for (int i = 0; i < 16; i++)
    {
        p = new pannel(this, 160, rectt[i].h);
        p->setGeometry(rectt[i].x, rectt[i].y, 161, rectt[i].h+1);
    }

    QFont ft1;
    ft1.setPointSize(12);

    QFont ft2;
    ft2.setPointSize(10);

    for (int i = 0; i < 27; i++)
    {
        l = new QLabel(strr[i].s, this);
        if (i < 14)
            l->setFont(ft1);
        else
            l->setFont(ft2);

        l->setGeometry(strr[i].x, strr[i].y, 120, 16);

        if (i < 24)
        {
            ledd = new led(this, strr[i].key_no, strr[i].c);
            ledd->setGeometry(strr[i].x - 25,strr[i].y, 22, 22);
        }
    }

    l = new QLabel("按键值", this);
    l->setFont(ft1);
    l->setGeometry(70, 430, 80, 20);

    QLineEdit *lD = new QLineEdit(this);
    lD->setGeometry(130, 425, 80, 30);
    lD->setDisabled(true);
    lD->setText("无");
}

MainWindow::~MainWindow()
{

}
