#include "ActionReachPointModel.h"
#include "PersonModel.h"

#include <QPointF>

ActionReachPointModel::ActionReachPointModel(PersonModel &person,
                                             QPointF destination,
                                             unsigned int timeout)
    : ActionAbstractModel(person, timeout), destination(destination) {}

void ActionReachPointModel::operator()() {
  if (!getIsRunning())
    return;

  QVector2D direction =
      QVector2D(destination) - QVector2D(getPerson().getPosition());
  double directionMag = direction.length();
  direction.normalize();
  if (directionMag < 100) {
    double factor = directionMag / 100;
    direction *= factor;
  } else {
    direction *= 1; // 1 is the max speed
  }

  getPerson().setAcceleration(direction - getPerson().getSpeed());

  QVector2D newSpeed = getPerson().getSpeed() += getPerson().getAcceleration();
  getPerson().setSpeed(newSpeed);

  QVector2D newPosition = QVector2D(getPerson().getPosition()) +=
      getPerson().getSpeed();
  getPerson().setPosition(newPosition.toPointF());

  getPerson().setAcceleration(QVector2D(0, 0));

  // Due to round of floats, probably some information get lost, so a distance
  // of 0.01 from the target is considered acceptable
  if (directionMag <= 0.01) {
    int x = qrand() % 500;
    int y = qrand() % 500;
    destination = QPoint(x, y);
  }
}