#ifndef ACTOR_H
#define ACTOR_H

enum ActorHealthState { HEALTHY, INFECTED, RECOVERED, DEAD };

#include "../BehaviourTree/Tree.h"
#include "Entity.h"
#include <QVector2D>

class Simulation;
class ActorAI;

using namespace BehaviourTree;

class ActorHealhStateUndefined {};

class Actor : public Entity, public Tree {
public:
  Actor(int id, Simulation &simulation, QVector2D position, float speed,
        ActorHealthState state, QVector<QVector2D> waypoints, uint waitTime,
        uint range, uint timeToRecover, uint deathChance, uint infectRateo);
  void update() override;
  void render(QPainter &painter) override;

  QVector2D position() const;
  float speed() const;
  ActorHealthState healthState() const;

  void setPosition(QVector2D position);
  void setSpeed(float speed);

  void setHealthState(ActorHealthState state);

  // CAN THROW ActorHealthStateUndefined IF value IS NOT CORRECT
  static ActorHealthState healthState(int value);

private:
  int id_;
  Simulation &simulation_;
  QVector2D position_;
  float speed_;
  ActorHealthState healthState_;
};

#endif // ACTOR_H