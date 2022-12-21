#include "person.h"

person::person(QObject *parent) : QObject{parent} {}

void person::SetWeight(double w) {
  if (mWeight != w) {
    mWeight = w;
    emit WeightChanged();
  }
}
