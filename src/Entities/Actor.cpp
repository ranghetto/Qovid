#include "Actor.h"
#include "../AI/CheckAlive.h"
#include "../AI/CheckInfected.h"
#include "../AI/InfectActorsInRange.h"
#include "../AI/Patrol.h"
#include "../AI/RecoverDeath.h"
#include "../BehaviourTree/Sequence.h"
#include <QPainter>

Actor::Actor(QVector2D position, float speed, ActorHealthState state,
             QVector<QVector2D> waypoints, float waitTime, float range,
             float timeToRecover, float deathChance, float infectRateo)
    : Tree(new Sequence({
          new CheckAlive(*this),
          new Patrol(*this, waypoints, waitTime),
          new CheckInfected(*this),
          new InfectActorsInRange(*this, range, infectRateo),
          new RecoverDeath(*this, timeToRecover, deathChance),
      })),
      position_(position), speed_(speed), healthState_(state) {}
QVector2D Actor::position() const { return position_; }

float Actor::speed() const { return speed_; }

ActorHealthState Actor::healthState() const { return healthState_; }

void Actor::setPosition(QVector2D position) { position_ = position; }

void Actor::setSpeed(float speed) { speed_ = speed; }

void Actor::setHealthState(ActorHealthState state) { healthState_ = state; }

void Actor::update() { Tree::update(); }

void Actor::render(QPainter &painter) {
  painter.setPen(Qt::PenStyle::NoPen);
  painter.setBrush(QBrush(Qt::black));
  if (healthState_ == ActorHealthState::HEALTHY) {
    painter.setBrush(QBrush(Qt::green));
  }
  if (healthState_ == ActorHealthState::INFECTED) {
    painter.setBrush(QBrush(Qt::red));
  }
  if (healthState_ == ActorHealthState::DEAD) {
    painter.setBrush(QBrush(Qt::lightGray));
  }
  if (healthState_ == ActorHealthState::RECOVERED) {
    painter.setBrush(QBrush(Qt::blue));
  }
  painter.drawEllipse(position_.toPoint(), 5, 5);
}
