#include "CheckInfected.h"

CheckInfected::CheckInfected(const Actor &actor) : actor_(actor) {}

NodeState CheckInfected::evaluate() {
  if (actor_.healthState() == ActorHealthState::INFECTED) {
    state_ = NodeState::SUCCESS;
    return state_;
  }

  state_ = NodeState::FAILURE;
  return state_;
}