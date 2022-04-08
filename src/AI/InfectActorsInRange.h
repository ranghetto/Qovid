#ifndef INFECT_ACTORS_IN_RANGE_H
#define INFECT_ACTORS_IN_RANGE_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"

using namespace BehaviourTree;

class InfectActorsInRange : public Node {
public:
  InfectActorsInRange(Actor &actor, int range);
  NodeState evaluate(qint64 deltaTime) override;

private:
  Actor &actor_;
  int range_;
};

#endif // INFECT_ACTORS_IN_RANGE_H