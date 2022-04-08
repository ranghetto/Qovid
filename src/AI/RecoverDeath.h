#ifndef RECOVERY_H
#define RECOVERY_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"
#include <QElapsedTimer>

using namespace BehaviourTree;

class RecoverDeath : public Node {
public:
  RecoverDeath(Actor &actor, int timeToRecover, float deathChance);
  NodeState evaluate() override;

private:
  Actor &actor_;
  int timeToRecover_;
  float deathChance_;
  bool timerStarted_;
  QElapsedTimer timer_;
};

#endif // RECOVERY_H