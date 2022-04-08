#ifndef RECOVERY_H
#define RECOVERY_H

#include "../BehaviourTree/Node.h"
#include "../Entities/Actor.h"
#include <QElapsedTimer>

using namespace BehaviourTree;

class PermanentRecovery : public Node {
public:
  PermanentRecovery(Actor &actor, int timeToRecover);
  NodeState evaluate(qint64 deltaTime) override;

private:
  Actor &actor_;
  int timeToRecover_;
  bool timerStarted_;
  QElapsedTimer timer_;
};

#endif // RECOVERY_H