#include "ActionReachPointModel.h"
#include "PersonModel.h"

#include <QPointF>

ActionReachPointModel::ActionReachPointModel(QPointF destination,
                                             unsigned int timeout)
    : ActionAbstractModel(timeout), destination(destination) {}

void ActionReachPointModel::operator()(PersonModel &person) {
  if (!getIsRunning())
    return;

  QVector2D direction =
      QVector2D(destination) - QVector2D(person.getPosition());
  double directionMag = direction.length();
  direction.normalize();
  if (directionMag < 100) {
    double factor = directionMag / 100;
    direction *= factor;
  } else {
    direction *= 1; // 1 is the max speed
  }

  person.setAcceleration(direction - person.getSpeed());

  QVector2D newSpeed = person.getSpeed() += person.getAcceleration();
  person.setSpeed(newSpeed);

  QVector2D newPosition = QVector2D(person.getPosition()) += person.getSpeed();
  person.setPosition(newPosition.toPointF());

  person.setAcceleration(QVector2D(0, 0));

  // Due to round of floats, probably some information get lost, so a distance
  // of 0.01 from the target is considered acceptable
  if (directionMag <= 0.01) {
    int x = qrand() % 500;
    int y = qrand() % 500;
    destination = QPoint(x, y);
  }
}