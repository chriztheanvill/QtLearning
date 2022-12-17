#include "widget.h"
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent) : QWidget(parent) {
  // First Name
  QLabel *firstNameLabel = new QLabel("FirstName", this);
  firstNameLabel->setMinimumSize(70, 50);
  firstNameLabel->move(10, 10);

  QLineEdit *firstNameLineEdit = new QLineEdit(this);
  firstNameLineEdit->setMinimumSize(200, 50);
  firstNameLineEdit->move(100, 10);

  // Last name
  QLabel *lastNameLabel = new QLabel("LastName", this);
  lastNameLabel->setMinimumSize(70, 50);
  lastNameLabel->move(10, 70);

  QLineEdit *lastNameLineEdit = new QLineEdit(this);
  lastNameLineEdit->setMinimumSize(200, 50);
  lastNameLineEdit->move(100, 70);

  QLabel *ageNameLabel = new QLabel("Age", this);
  ageNameLabel->setMinimumSize(200, 50);
}

Widget::~Widget() {}
