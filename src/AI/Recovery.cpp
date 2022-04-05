#include "Recovery.h"

Recovery::Recovery(Actor &actor, int timeToRecover)
    : actor_(actor), timeToRecover_(timeToRecover), wasInfected_(false) {}

NodeState Recovery::evaluate(qint64 deltaTime) {
  if (actor_.healthState() == ActorHealthState::INFECTED && !wasInfected_) {
    wasInfected_ = true;
    timer_.start();
  }

  if (timer_.elapsed() >= timeToRecover_) {
    actor_.setHealthState(ActorHealthState::RECOVERED);
  }

  state_ = NodeState::RUNNING;
  return state_;
}