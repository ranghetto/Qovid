#ifndef INFECT_ACTORS_IN_RANGE_H
#define INFECT_ACTORS_IN_RANGE_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"

using namespace BehaviourTree;

class InfectActorsInRange : public Node {
public:
  InfectActorsInRange(const Actor &actor, uint range, int infectRateo);
  NodeState evaluate(const Simulation &s) override;

private:
  const Actor &actor_;
  const uint range_;
  // int because needs to be compared with other int values
  const int infectRateo_;
};

#endif // INFECT_ACTORS_IN_RANGE_H