#ifndef WORLD_H
#define WORLD_H

#include "../Entities/Actor.h"
#include "../Entities/Entity.h"
#include <QVector>

class Simulation;

class World {
public:
  World(Simulation &, uint, uint, uint, uint, uint, uint);
  void addEntity(Entity &entity);
  QVector<Entity *> entities() const;
  int infectedCount() const;
  int actorsCount() const;
  QVector<Actor *> findNearbyActors(QVector2D center, int range) const;
  ~World();

private:
  QVector<Entity *> entities_;
};

#endif // WORLD_H