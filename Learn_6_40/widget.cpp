#include "widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) {
  // Button 1
  QFont buttonFont("Times", 20, QFont::Bold);
  QPushButton *button1 = new QPushButton("Button1", this);
  button1->setMinimumSize(200, 100);
  button1->setFont(buttonFont);
  connect(button1, &QPushButton::clicked,
          [=]() { qDebug() << "Button1 clicked"; });

  // Button 2
  QPushButton *button2 = new QPushButton("Button2", this);
  button2->setMinimumSize(200, 100);
  button2->setFont(buttonFont);
  button2->move(205, 0);
  connect(button2, &QPushButton::pressed,
          [=]() { qDebug() << "Button2 pressed ++++"; });
  connect(button2, &QPushButton::released,
          [=]() { qDebug() << "Button2 released ----"; });
  connect(button2, &QPushButton::clicked,
          [=]() { qDebug() << "Button2 clicked"; });
}

Widget::~Widget() {}
