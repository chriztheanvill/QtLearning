#include "widget.h"
#include <QLabel>
#include <QTextEdit>

Widget::Widget(QWidget *parent) : QWidget(parent) {
  SetupUI();
  setFixedSize(400, 400);
}

Widget::~Widget() {}

void Widget::SetupUI() {
  QFont labelFont("Times", 10, QFont::Bold);
  QLabel *mLabel = new QLabel("This is my text", this);
  mLabel->setFont(labelFont);
  mLabel->move(100, 25);

  QTextEdit *textEdit = new QTextEdit(this);
  textEdit->move(70, 55);
}
