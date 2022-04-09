#ifndef RECOVERY_H
#define RECOVERY_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"
#include <QElapsedTimer>

using namespace BehaviourTree;

class RecoverDeath : public Node {
public:
  RecoverDeath(Actor &actor, uint timeToRecover, uint deathChance);
  NodeState evaluate() override;

private:
  Actor &actor_;
  const uint timeToRecover_;
  const uint deathChance_;
  bool timerStarted_;
  QElapsedTimer timer_;
};

#endif // RECOVERY_H