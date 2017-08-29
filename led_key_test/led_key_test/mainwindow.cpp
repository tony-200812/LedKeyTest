#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "led.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    led *l;
    ui->setupUi(this);
    this->setFixedSize(600, 550);
    this->setWindowIconText("灯键板调试程序");

    l = new led(this, Qt::red, 2);
    l->setGeometry(3, 3, 3, 3);

    l = new led(this, Qt::red, 3);
    l->setGeometry(3, 33, 3, 3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
