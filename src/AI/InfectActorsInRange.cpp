#include "InfectActorsInRange.h"
#include "../Controllers/Simulation.h"

InfectActorsInRange::InfectActorsInRange(Actor &actor, int range)
    : actor_(actor), range_(range) {}

NodeState InfectActorsInRange::evaluate(qint64 deltaTime) {

  QVector<Actor *> people = Simulation::instance().world()->findNearbyActors(
      actor_.position(), range_);

  if (actor_.healthState() == ActorHealthState::INFECTED) {
    for (auto p : people) {
      p->setHealthState(ActorHealthState::INFECTED);
    }
  }

  state_ = NodeState::RUNNING;
  return state_;
}