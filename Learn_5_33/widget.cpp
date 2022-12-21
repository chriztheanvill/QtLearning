#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  // init
  mPerson.SetWeight(ui->doubleSpinBox_Weight->value());
  mTime = ui->doubleSpinBox_Time->value();
  mSpeed = ui->doubleSpinBox_Speed->value();

  // Connect ui commponents
  connect(ui->doubleSpinBox_Weight, &QDoubleSpinBox::valueChanged, this,
          &Widget::WeightChanged);
  connect(ui->doubleSpinBox_Time, &QDoubleSpinBox::valueChanged, this,
          &Widget::TimeChanged);
  connect(ui->doubleSpinBox_Speed, &QDoubleSpinBox::valueChanged, this,
          &Widget::SpeedChanged);

  // Update Calory Count label
  connect(this, &Widget::CaloryCountChanged, [=]() {
    ui->label_CaloryCount->setText(QString::number(mCaloryCount));
  });

  CalculateCalories();
}

Widget::~Widget() { delete ui; }

void Widget::CalculateCalories() {
  mCaloryCount = ((0.0215 * (mSpeed * mSpeed * mSpeed)) -
                  (0.1765 * (mSpeed * mSpeed)) + (0.8710 * mSpeed) + 1.4577) *
                 mPerson.GetWeight() * mTime;
  emit CaloryCountChanged();
}

void Widget::WeightChanged(double w) {
  mPerson.SetWeight(w);
  CalculateCalories();
}

void Widget::TimeChanged(double t) {
  mTime = t;
  CalculateCalories();
}

void Widget::SpeedChanged(double s) {
  mSpeed = s;
  CalculateCalories();
}
