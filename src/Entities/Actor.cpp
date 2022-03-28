#include "Actor.h"
#include "../AI/ActorAI.h"
#include <QPainter>

Actor::Actor(QVector<QVector2D> waypoints, QVector2D position, float speed)
    : position_(position), speed_(speed) {
  // TODO spostare creazione cervello nel World
  ai_ = new ActorAI(*this, waypoints, 5000);
}

QVector2D Actor::position() const { return position_; }

float Actor::speed() const { return speed_; }

void Actor::setPosition(QVector2D position) { position_ = position; }

void Actor::setSpeed(float speed) { speed_ = speed; }

void Actor::update(qint64 deltaTime) {
  if (healthState_ == ActorHealthState::DEAD)
    return;
  ai_->update(deltaTime);
}

void Actor::render(QPainter &painter) {
  painter.setPen(Qt::PenStyle::NoPen);
  painter.setBrush(QBrush(Qt::green));
  painter.drawEllipse(position_.toPoint(), 5, 5);
}
