#ifndef ACTOR_H
#define ACTOR_H

enum ActorHealthState { HEALTHY, INFECTED, RECOVERED, DEAD };

class ActorAI;
#include "../BehaviourTree/Tree.h"
#include "Entity.h"
#include <QVector2D>

using namespace BehaviourTree;

class Actor : public Entity, public Tree {
public:
  Actor(QVector2D position, float speed, ActorHealthState state,
        QVector<QVector2D> waypoints, uint waitTime, uint range,
        uint timeToRecover, uint deathChance, uint infectRateo);
  void update(const Simulation &s) override;
  void render(QPainter &painter) override;

  QVector2D position() const;
  float speed() const;
  ActorHealthState healthState() const;

  void setPosition(QVector2D position);
  void setSpeed(float speed);

  void setHealthState(ActorHealthState state);

private:
  QVector2D position_;
  float speed_;
  ActorHealthState healthState_;
};

#endif // ACTOR_H