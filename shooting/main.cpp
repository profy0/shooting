#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumHeight(w.getRadius()+120);
    w.setMaximumHeight(w.getRadius()+120);
    w.setMinimumWidth(w.getRadius()+50);
    w.setMaximumWidth(w.getRadius()+50);
    w.show();
    return a.exec();
}
