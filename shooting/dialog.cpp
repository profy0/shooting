#include "dialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>

WDialog::WDialog(QWidget *parent)
      : QDialog(parent)
  {

    label = new QLabel("Введите радиус (число от 300):");
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    label2 = new QLabel("Введите количество выстрелов:");
    lineEdit2 = new QLineEdit;
    label2->setBuddy(lineEdit2);

    addButton = new QPushButton("OK");
    addButton->setDefault(true);
    addButton->setEnabled(false);

    closeButton = new QPushButton("Cancel");

    connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableButton(const QString &)));
    connect(lineEdit2, SIGNAL(textChanged(const QString &)), this, SLOT(enableButton2(const QString &)));
    connect(addButton, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()),this, SLOT(close()));

    QVBoxLayout *topLeftLayout = new QVBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *topLeftLayout2 = new QVBoxLayout;
    topLeftLayout->addWidget(label2);
    topLeftLayout->addWidget(lineEdit2);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addLayout(topLeftLayout2);

    QHBoxLayout *rightLayout = new QHBoxLayout;
    rightLayout->addWidget(closeButton);
    rightLayout->addWidget(addButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setWindowTitle(("Ввод данных"));
    setFixedHeight(sizeHint().height());
}


void WDialog::findClicked() {
    amount = lineEdit->text();
    hitCount = lineEdit2->text();
    close();
}

void WDialog::enableButton(const QString &text) {
    ok = !text.isEmpty();
    addButton->setEnabled(ok&&ok2);
}

void WDialog::enableButton2(const QString &text) {
    ok2 = !text.isEmpty();
    addButton->setEnabled(ok&&ok2);
}
