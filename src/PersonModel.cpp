#include "PersonModel.h"
#include "ActionAbstractModel.h"

PersonModel::PersonModel(QPoint position, QVector2D speed,
                         QVector2D acceleration, QPoint bounds)
    : position(position), speed(speed), acceleration(acceleration),
      bounds(bounds) {}

void PersonModel::doAction() {
  if (!currentAction)
    return;
  (*currentAction)();
}

void PersonModel::setPosition(QPoint position) { this->position = position; }

void PersonModel::setSpeed(QVector2D speed) { this->speed = speed; }

void PersonModel::setAcceleration(QVector2D acceleration) {
  this->acceleration = acceleration;
}

void PersonModel::setBounds(QPoint bounds) { this->bounds = bounds; }

void PersonModel::setAction(ActionAbstractModel &action) {
  this->currentAction = &action;
}

void PersonModel::limitSpeed(unsigned int speedLimit) {
  if (speed.length() > speedLimit)
    speed.normalize();
  speed *= speedLimit;
}

QPoint PersonModel::getPosition() const { return position; }

QVector2D PersonModel::getSpeed() const { return speed; }

QVector2D PersonModel::getAcceleration() const { return acceleration; }

QPoint PersonModel::getBounds() const { return bounds; }

ActionAbstractModel &PersonModel::getCurrentAction() const {
  return *currentAction;
}

void PersonModel::draw(QPainter &painter) {
  painter.setBrush(QBrush(QColor(52, 180, 235)));
  painter.setPen(Qt::PenStyle::NoPen);
  painter.drawEllipse(position, 10, 10);
}