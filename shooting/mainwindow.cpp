#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "target.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ww = new QPaintWidget (this);
    ui->verticalLayout->addWidget(ww);
    ui->label->setText("Всего попаданий: 0");
    ui->label_2->setText("Всего промахов: 0");
    ui->pushButton->setText("Выстрелить!");
    connect(ww, SIGNAL(hit()), this, SLOT(Count()));
    connect(ww, SIGNAL(goodHit()), this, SLOT(Good()));
    connect(ww, SIGNAL(badHit()), this, SLOT(Bad()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getRadius()
{
    return ww->getR();
}

bool MainWindow::check(QString s)
{
    for(auto now : s) {
        if(!(now>='0'&&now<='9')) {
            return 0;
        }
    }
    return 1;
}

void MainWindow::clearLines()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::Count()
{
    if(ww->getH()==0) {
        QMessageBox::information(this, "Игра закончена", "Попаданий: " + QString::number(ww->getG()) + ", Промахов: " + QString::number(ww->getC()-ww->getG()));
        clearLines();
        close();
    }
}

void MainWindow::Good()
{
    ui->label->setText("Всего попаданий: " + QString::number(ww->getG()));
    clearLines();
}

void MainWindow::Bad()
{
    ui->label_2->setText("Всего промахов: " + QString::number(ww->getC()-ww->getG()));
    clearLines();
}

void MainWindow::on_pushButton_clicked()
{
    QString sx = ui->lineEdit->text();
    QString sy = ui->lineEdit_2->text();

    if(check(sx)&&check(sy)) {
        int x = sx.toInt();
        int y = sy.toInt();
        ww->hitByCoord(x,y);
    } else {
        QMessageBox::warning(this, "Ошибка", "Введите целые числа больше 0");
        clearLines();
    }
}
