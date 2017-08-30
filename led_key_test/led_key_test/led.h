#ifndef LED_H
#define LED_H

#include <QWidget>
#include <QTimer>

enum led_status
{
    led_light,
    led_close,
    led_twinkle,
};

class led : public QWidget
{
    Q_OBJECT
public:
    explicit led(QWidget *parent = 0, quint8 led_no = 0, QColor color = Qt::red);

signals:

public slots:
    void setLedStat(enum led_status stat);

private slots:
    void mousePress();

private:
    bool l;
    int  timerId;
    QTimer *timer;
    QColor c;
    quint8 number;
    enum led_status status;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);

Q_SIGNALS:
    void send_status(quint8 no, enum led_status stat);
};

#endif // LED_H
