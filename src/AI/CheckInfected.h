#ifndef CHECK_INFECTED_H
#define CHECK_INFECTED_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"

using namespace BehaviourTree;

class CheckInfected : public Node {
public:
  CheckInfected(const Actor &actor);
  NodeState evaluate() override;

private:
  const Actor &actor_;
};

#endif // CHECK_INFECTED_H