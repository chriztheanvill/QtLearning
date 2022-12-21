#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class person : public QObject {
  Q_OBJECT
public:
  explicit person(QObject *parent = nullptr);

  double GetWeight() const { return mWeight; }
  void SetWeight(double w);

signals:
  void WeightChanged();

private:
  double mWeight{};
};

#endif // PERSON_H
