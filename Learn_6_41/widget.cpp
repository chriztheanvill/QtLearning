#include "widget.h"
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

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

  // City
  QLabel *cityLabel = new QLabel("City", this);
  cityLabel->setMinimumSize(70, 50);
  cityLabel->move(10, 130);

  QLineEdit *cityLineEdit = new QLineEdit(this);
  cityLineEdit->setMinimumSize(200, 50);
  cityLineEdit->move(100, 130);

  QFont buttonFont("Times", 20, QFont::Bold);
  QPushButton *button = new QPushButton("Grab data", this);
  button->setFont(buttonFont);
  button->move(80, 190);

  // Connections
  connect(button, &QPushButton::clicked, [=]() {
    QString firstName = firstNameLineEdit->text();
    QString lastName = lastNameLineEdit->text();
    QString city = cityLineEdit->text();

    if (!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty()) {
      // If neither field is empty we fall here
      qDebug() << "First Name: " << firstName;
      qDebug() << "Last Name: " << lastName;
      qDebug() << "City: " << city;
    } else {
      qDebug() << "One field is empty.";
    }
  }); // Connections lambda

  // Signals
  // CursorPosition Changed
  //  connect(firstNameLineEdit, &QLineEdit::cursorPositionChanged, [=] {
  //    qDebug() << "The current cursor position is: "
  //             << firstNameLineEdit->cursorPosition();
  //  });

  // EditingFinished: emited when user clicks enter or when line edit looses
  // focus.
  connect(firstNameLineEdit, &QLineEdit::editingFinished,
          [=] { qDebug() << "Editing finished "; });

  // returnPressed
  connect(firstNameLineEdit, &QLineEdit::returnPressed, [=] {
    qDebug() << "firtsNameLineEdit Return Pressed ";
    lastNameLineEdit->setFocus();
  });

  // returnPressed
  connect(lastNameLineEdit, &QLineEdit::returnPressed, [=] {
    qDebug() << "lastNameLineEdit Return Pressed ";
    cityLineEdit->setFocus();
  });

  // returnPressed
  connect(cityLineEdit, &QLineEdit::returnPressed, [=] {
    qDebug() << "cityLineEdit Return Pressed ";
    button->setFocus();
  });

  // Hint text
  firstNameLineEdit->setPlaceholderText("First Name");
  lastNameLineEdit->setPlaceholderText("Last Name");
  cityLineEdit->setPlaceholderText("City");
}

Widget::~Widget() {}
