/* Re-hice esta parte, por que no imprimia qDebug() */

#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Widget w;
  w.show();
  return a.exec();
}
