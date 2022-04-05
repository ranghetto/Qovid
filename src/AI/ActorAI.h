#ifndef ACTOR_AI_H
#define ACTOR_AI_H

#include "../BehaviourTree/Sequence.h"
#include "../BehaviourTree/Tree.h"
#include "../Entities/Actor.h"

using namespace BehaviourTree;

class ActorAI : public Tree {
public:
  ActorAI(Actor &actor, QVector<QVector2D> waypoints, float waitTime,
          float range);
};

#endif // ACTOR_AI_H