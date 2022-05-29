#include "target.h"
#include <QPainter>
#include <QDebug>
#include "dialog.h"

#include <QMouseEvent>
#include <QMessageBox>
QPaintWidget::QPaintWidget(QWidget *parent)
    : QWidget(parent)
{
    bool error = 0;
    while(!error) {
        WDialog *dialog = new WDialog;
        dialog->exec();
        QString amount = dialog->amount;
        QString ht = dialog->hitCount;
        if(amount.size()==0||ht.size()==0) {
            exit(0);
        }
        if(!checkInt(amount)||amount.toInt()<300) {
            QMessageBox::warning(this, "Ошибка", "Радиус должен быть числом от 300");
            continue;
        }
        rr = amount.toInt();
        if(!checkInt(ht)) {
            QMessageBox::warning(this, "Ошибка", "Количество выстрелов должно быть числом");
            continue;
        }
        hits = ht.toInt();
        error = 1;
    }
    count = 0;

}

int QPaintWidget::getR() const
{
    return rr;
}

int QPaintWidget::getC() const
{
    return count;
}

int QPaintWidget::getG() const
{
    return vec.size();
}

int QPaintWidget::getH() const
{
    return hits;
}



void QPaintWidget::hitByCoord(int nx, int ny)
{
    x = nx;
    y = ny;
    if(checkHit()) emit goodHit(); else emit badHit();
    hits--;
    emit hit();

    update();
}

bool QPaintWidget::checkHit()
{
    bool ok = 0;
    count++;
    x-=width()/2;
    y-=height()/2;
    if(x*x+y*y<=(rr/2)*(rr/2)&&y+height()/2<=height()/2)
    {
        vec.push_back({x+width()/2,y+height()/2});
        ok = 1;
    }

    x+=width()/2;
    y+=height()/2;

    int a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
    int b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
    int c = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);

    if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)) {
        vec.push_back({x,y});
        ok = 1;
    }
    return ok;
}

bool QPaintWidget::checkInt(QString s)
{
    for(auto now : s) {
        if(!(now>='0'&&now<='9')) {
            return 0;
        }
    }
    return 1;
}

void QPaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    painter.setBrush(Qt::gray);
    QPolygon p;
    p << QPoint(width()/2-rr/2,height()/2+rr/2) << QPoint(width()/2,height()/2+rr/2) << QPoint(width()/2, height()/2);
    x1 = width()/2-rr/2;
    y1 = height()/2+rr/2;
    x2 = width()/2;
    y2 = height()/2+rr/2;
    x3 = width()/2;
    y3 = height()/2;
    painter.drawPie(width()/2-rr/2,height()/2-rr/2, rr, rr, 0*16, 180*16);
    painter.drawPolygon(p);
    for(auto now : vec) {
        painter.setBrush(Qt::green);
        painter.drawEllipse(now.first-3,now.second-3,5,5);
    }

    painter.end();
}

void QPaintWidget::mousePressEvent(QMouseEvent *eventPress)
{
    QPoint pp =  eventPress->pos();
    x = pp.rx();
    y = pp.ry();
    if(checkHit()) emit goodHit(); else emit badHit();
    hits--;
    emit hit();
    update();
}
