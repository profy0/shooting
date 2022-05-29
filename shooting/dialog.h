#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class WDialog : public QDialog
{

    Q_OBJECT

public:

    WDialog(QWidget *parent = 0);
    QString amount, hitCount;
    bool ok=0,ok2=0;

private slots:

    void findClicked();
    void enableButton(const QString &text);
    void enableButton2(const QString &text);

private:
    QLabel *label;
    QLabel *label2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QPushButton *addButton;
    QPushButton *closeButton;
};

#endif // DIALOG_H
