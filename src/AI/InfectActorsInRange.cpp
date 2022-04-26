#include "InfectActorsInRange.h"
#include "../Controllers/Simulation.h"

InfectActorsInRange::InfectActorsInRange(const Actor &actor, uint range,
                                         int infectRateo)
    : actor_(actor), range_(range), infectRateo_(infectRateo) {}

NodeState InfectActorsInRange::evaluate(const Simulation &s) {

  QVector<Actor *> people =
      s.world()->findNearbyActors(actor_.position(), range_);

  for (auto p : people) {
    if (p && p->healthState() == ActorHealthState::HEALTHY)
      // TODO probably this needs to be: select 20% of the total people around
      // this actor and infect them, the other 80% stay healthy
      if (qrand() % 100 < infectRateo_)
        p->setHealthState(ActorHealthState::INFECTED);
  }

  state_ = NodeState::SUCCESS;
  return state_;
}