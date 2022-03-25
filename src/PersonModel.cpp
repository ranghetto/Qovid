#include "PersonModel.h"
#include "ActionAbstractModel.h"

PersonModel::PersonModel(QPointF position, QVector2D speed,
                         QVector2D acceleration, Status status)
    : position(position), speed(speed), acceleration(acceleration),
      status(status) {}

// TODO https://github.com/ranghetto/Qovid/issues/12
PersonModel::~PersonModel() { delete currentAction; }

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

void PersonModel::setStatus(Status status) { this->status = status; }

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

PersonModel::Status PersonModel::getStatus() const { return status; }

void PersonModel::draw(QPainter &painter) {
  painter.setBrush(QBrush(QColor(52, 180, 235)));
  painter.setPen(Qt::PenStyle::NoPen);
  painter.drawEllipse(position, 10, 10);
}