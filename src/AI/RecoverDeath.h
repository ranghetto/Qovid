#ifndef RECOVERY_H
#define RECOVERY_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"
#include <QElapsedTimer>

using namespace BehaviourTree;

class RecoverDeath : public Node {
public:
  RecoverDeath(Actor &actor, int timeToRecover, int deathChance);
  NodeState evaluate(const Simulation &s) override;

private:
  Actor &actor_;
  // int because needs to be compared with other int values
  const int timeToRecover_;
  const int deathChance_;
  bool timerStarted_;
  QElapsedTimer timer_;
};

#endif // RECOVERY_H