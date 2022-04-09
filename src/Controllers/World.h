#ifndef WORLD_H
#define WORLD_H

#include "../Entities/Actor.h"
#include "../Entities/Entity.h"
#include <QVector>

class World {
public:
  World(uint, uint, uint, uint, uint, uint);
  void addEntity(Entity &entity);
  QVector<Entity *> entities() const;
  QVector<Actor *> findNearbyActors(QVector2D center, int range) const;
  ~World();

private:
  QVector<Entity *> entities_;
};

#endif // WORLD_H