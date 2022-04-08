#ifndef PATROL_H
#define PATROL_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"
#include <QVector2D>
#include <QVector>

using namespace BehaviourTree;

class Patrol : public Node {
public:
  Patrol(Actor &actor, QVector<QVector2D> waypoints, float waitTime = 0.0f);
  NodeState evaluate() override;

private:
  QVector<QVector2D> waypoints_;
  int currentWaypointIndex_;
  float waitTime_; // milliseconds
  float waitCounter_;
  bool waiting_;
  Actor &actor_;
};

#endif // PATROL_H