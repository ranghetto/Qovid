#ifndef INFECT_ACTORS_IN_RANGE_H
#define INFECT_ACTORS_IN_RANGE_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"

using namespace BehaviourTree;

class InfectActorsInRange : public Node {
public:
  InfectActorsInRange(const Actor &actor, uint range, uint infectRateo);
  NodeState evaluate() override;

private:
  const Actor &actor_;
  const uint range_;
  const uint infectRateo_;
};

#endif // INFECT_ACTORS_IN_RANGE_H