#include "CheckAlive.h"

CheckAlive::CheckAlive(Actor &actor) : actor_(actor) {}

NodeState CheckAlive::evaluate() {
  // If actor is dead node failed so remaining nodes in the sequence
  // will not be executed
  // To handle death correctly it must be the first node of a sequence
  if (actor_.healthState() == ActorHealthState::DEAD) {
    state_ = NodeState::FAILURE;
    return state_;
  }

  state_ = NodeState::SUCCESS;
  return state_;
}