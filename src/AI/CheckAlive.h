
#ifndef CHECK_ALIVE_H
#define CHECK_ALIVE_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"

using namespace BehaviourTree;

class CheckAlive : public Node {
public:
  CheckAlive(Actor &actor);
  NodeState evaluate() override;

private:
  Actor &actor_;
  int range_;
};

#endif // CHECK_ALIVE_H