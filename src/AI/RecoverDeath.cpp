#include "RecoverDeath.h"
#include "../Controllers/Simulation.h"

RecoverDeath::RecoverDeath(Actor &actor, int timeToRecover, int deathChance)
    : actor_(actor), timeToRecover_(timeToRecover), deathChance_(deathChance),
      timerStarted_(false) {}

NodeState RecoverDeath::evaluate(const Simulation &s) {
  if (actor_.healthState() == ActorHealthState::RECOVERED) {
    state_ = NodeState::SUCCESS;
    return state_;
  }

  if (actor_.healthState() == ActorHealthState::INFECTED && !timerStarted_) {
    timer_.start();
    timerStarted_ = true;
  }

  if (timer_.elapsed() >= timeToRecover_ + s.pausedTime()) {
    if (qrand() % 100 < deathChance_)
      actor_.setHealthState(ActorHealthState::DEAD);
    else
      actor_.setHealthState(ActorHealthState::RECOVERED);
  }

  state_ = NodeState::RUNNING;
  return state_;
}