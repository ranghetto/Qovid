#include "PersonModel.h"
#include "ActionAbstractModel.h"

// TODO remove bounds
PersonModel::PersonModel(QPointF position, QVector2D speed,
                         QVector2D acceleration)
    : position(position), speed(speed), acceleration(acceleration) {}

void PersonModel::doAction() {
  if (!currentAction)
    return;
  (*currentAction)(*this);
}

void PersonModel::setPosition(QPointF position) { this->position = position; }

void PersonModel::setSpeed(QVector2D speed) { this->speed = speed; }

void PersonModel::setAcceleration(QVector2D acceleration) {
  this->acceleration = acceleration;
}

void PersonModel::setAction(ActionAbstractModel &action) {
  this->currentAction = &action;
}

void PersonModel::limitSpeed(float speedLimit) {
  if (speed.length() > speedLimit)
    speed.normalize();
  speed *= speedLimit;
}

QPointF PersonModel::getPosition() const { return position; }

QVector2D PersonModel::getSpeed() const { return speed; }

QVector2D PersonModel::getAcceleration() const { return acceleration; }

ActionAbstractModel &PersonModel::getCurrentAction() const {
  return *currentAction;
}

void PersonModel::draw(QPainter &painter) {
  painter.setBrush(QBrush(QColor(52, 180, 235)));
  painter.setPen(Qt::PenStyle::NoPen);
  painter.drawEllipse(position, 10, 10);
}