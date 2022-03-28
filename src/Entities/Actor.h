#ifndef ACTOR_H
#define ACTOR_H

enum ActorHealthState { HEALTHY, INFECTED, RECOVERED, DEAD };

class ActorAI;
#include "../BehaviourTree/Tree.h"
#include "Entity.h"
#include <QVector2D>

using namespace BehaviourTree;

class Actor : public Entity {
public:
  Actor(QVector<QVector2D> waypoints, QVector2D position = {0, 0},
        float speed = 1.0f);
  void update(qint64 deltaTime) override;
  void render(QPainter &painter) override;

  QVector2D position() const;
  float speed() const;

  void setPosition(QVector2D position);
  void setSpeed(float speed);

private:
  QVector2D position_;
  float speed_;
  ActorAI *ai_;
  ActorHealthState healthState_;
};

#endif // ACTOR_H