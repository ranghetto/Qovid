#include "ActorAI.h"
#include "Patrol.h"

ActorAI::ActorAI(Actor &actor, QVector<QVector2D> waypoints, float waitTime)
    : Tree(new Patrol(actor, waypoints, waitTime)) {}