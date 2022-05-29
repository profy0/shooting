#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPaintEvent>
#include "target.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getRadius();
    bool check(QString);
    void clearLines();

private slots:
    void Count();
    void Good();
    void Bad();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QPaintWidget *ww;
};
#endif // MAINWINDOW_H
