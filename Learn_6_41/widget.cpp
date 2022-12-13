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
}

Widget::~Widget() {}
