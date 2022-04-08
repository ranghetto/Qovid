#include "InfectActorsInRange.h"
#include "../Controllers/Simulation.h"

InfectActorsInRange::InfectActorsInRange(Actor &actor, int range)
    : actor_(actor), range_(range) {}

NodeState InfectActorsInRange::evaluate() {

  QVector<Actor *> people = Simulation::instance().world()->findNearbyActors(
      actor_.position(), range_);

  if (actor_.healthState() == ActorHealthState::INFECTED) {
    for (auto p : people) {
      if (p->healthState() == ActorHealthState::HEALTHY)
        // TODO probably this needs to be: select 20% of the total people around
        // this actor and infect them, the other 80% stay healthy
        // TODO configurable %, not hardcoded
        if (qrand() % 100 < 20)
          p->setHealthState(ActorHealthState::INFECTED);
    }
  }

  state_ = NodeState::RUNNING;
  return state_;
}