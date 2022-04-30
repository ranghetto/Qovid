#ifndef PATROL_H
#define PATROL_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"
#include <QVector2D>
#include <QVector>

using namespace BehaviourTree;

class Patrol : public Node {
public:
  Patrol(Actor &actor, QVector<QVector2D> waypoints, uint waitTime);
  NodeState evaluate(const Simulation &s) override;

private:
  Actor &actor_;
  const QVector<QVector2D> waypoints_;
  uint currentWaypointIndex_;
  const uint waitTime_; // milliseconds
  uint waitCounter_;
  bool waiting_;
};

#endif // PATROL_H