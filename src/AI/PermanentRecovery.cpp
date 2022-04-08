#include "PermanentRecovery.h"

PermanentRecovery::PermanentRecovery(Actor &actor, int timeToRecover)
    : actor_(actor), timeToRecover_(timeToRecover), timerStarted_(false) {}

NodeState PermanentRecovery::evaluate(qint64 deltaTime) {
  if (actor_.healthState() == ActorHealthState::RECOVERED) {
    state_ = NodeState::SUCCESS;
    return state_;
  }

  if (actor_.healthState() == ActorHealthState::INFECTED && !timerStarted_) {
    timer_.start();
    timerStarted_ = true;
  }

  if (timer_.elapsed() >= timeToRecover_)
    actor_.setHealthState(ActorHealthState::RECOVERED);

  state_ = NodeState::RUNNING;
  return state_;
}