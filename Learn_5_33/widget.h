#ifndef WIDGET_H
#define WIDGET_H

#include "person.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void CalculateCalories();
  void WeightChanged(double w);
  void TimeChanged(double t);
  void SpeedChanged(double s);

signals:
  void CaloryCountChanged();

private:
  Ui::Widget *ui;

  person mPerson;
  double mTime;
  double mSpeed;
  double mCaloryCount;
};
#endif // WIDGET_H
