#include "ActorAI.h"
#include "InfectActorsInRange.h"
#include "Patrol.h"

ActorAI::ActorAI(Actor &actor, QVector<QVector2D> waypoints, float waitTime,
                 float range)
    : Tree(new Sequence({new Patrol(actor, waypoints, waitTime),
                         new InfectActorsInRange(actor, range)})) {}