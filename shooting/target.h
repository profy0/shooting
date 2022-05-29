#ifndef TARGET_H
#define TARGET_H


#include <QWidget>

class QPaintEvent;
class QMouseEvent;

class QPaintWidget  : public QWidget
{

    Q_OBJECT

public:
    explicit QPaintWidget (QWidget * parent = 0);
    int getR() const;  // радиус
    int getC() const ;  // количество совершенных выстрелов
    int getG() const;  // количество попаданий
    int getH() const;  // количество выстрелов введенное пользователем
    void hitByCoord(int,int);
    bool checkHit();
    bool checkInt(QString);

private:
    bool clicked;
    int x,y;
    int x1,x2,x3,y1,y2,y3,rr,hits;
    std::vector <std::pair<int,int> > vec;
    int count, miss;

signals:
    void hit();
    void goodHit();
    void badHit();

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *eventPress) override;

};

#endif // TARGET_H
