#include "led.h"
#include <QImage>
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QTimer>

led::led(QWidget *parent, quint8 led_no, QColor color) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    setFixedSize(20, 20);

    c = color;
    number = led_no;
    status = led_close;
    timerId = startTimer(500);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mousePress()));
}

void led::paintEvent(QPaintEvent *event)
{
    event = event;

    QPainterPath path;
    path.addEllipse(QPointF(10, 10), 9, 9);

    QPainter painter(this);

    if (status == led_light)
    {
        painter.fillPath(path, QBrush(c, Qt::SolidPattern));
    }
    else if (status == led_close)
    {
        painter.fillPath(path, QBrush(Qt::black, Qt::SolidPattern));
    }
    else if (status == led_twinkle)
    {
        if (l)
        {
            l = false;
            painter.fillPath(path, QBrush(Qt::black, Qt::SolidPattern));
        }
        else
        {
            l = true;
            painter.fillPath(path, QBrush(c, Qt::SolidPattern));
        }
    }
}

void led::mousePressEvent(QMouseEvent *event)
{
    event = event;

    timer->start(300);
}
\
void led::mousePress()
{
    timer->stop();

    if (status == led_light)
    {
        status = led_close;
    }
    else if (status == led_close)
    {
        status = led_light;
    }
    else if (status == led_twinkle)
    {
        status = led_close;
    }

    emit send_status(number, status);
    update();
}

void led::mouseDoubleClickEvent(QMouseEvent *event)
{
    event = event;

    timer->stop();

    if (status == led_light)
    {
        status = led_twinkle;
    }
    else if (status == led_close)
    {
        status = led_twinkle;
    }
    else if (status == led_twinkle)
    {
        status = led_close;
    }

    emit send_status(number, status);
    update();
}

void led::timerEvent(QTimerEvent *event)
{
    event = event;

    if (status == led_twinkle)
    {
        update();
    }
}

void led::setLedStat(enum led_status stat)
{
    status = stat;

    if (status == led_light)
    {
        status = led_close;
    }
    else if (status == led_close)
    {
        status = led_light;
    }
    else if (status == led_twinkle)
    {
        status = led_close;
    }

    emit send_status(number, status);
    update();
}

