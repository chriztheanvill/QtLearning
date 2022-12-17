#include "widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) {
  // Clicked Signal
  QFont buttonFront("Times", 20, QFont::Bold);
  QPushButton *button1 = new QPushButton("Button1", this);
  button1->setMinimumSize(200, 100);
  button1->setFont(buttonFront);
  connect(button1, &QPushButton::clicked,
          [=]() { qDebug() << "Button1 clicked"; });

  // Button 2
  QPushButton *button2 = new QPushButton("Button2", this);
  button2->setMinimumSize(200, 100);
  button2->move(200, 0);
  button2->setFont(buttonFront);
  connect(button2, &QPushButton::pressed,
          [=]() { qDebug() << "Button2 pressed"; });
  connect(button2, &QPushButton::released,
          [=]() { qDebug() << "Button2 released"; });
}

Widget::~Widget() {}
