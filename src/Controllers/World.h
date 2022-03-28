#ifndef WORLD_H
#define WORLD_H

#include "../Entities/Entity.h"
#include <QVector>

class World {
public:
  World();
  void addEntity(Entity &entity);
  QVector<Entity *> entities() const;

private:
  QVector<Entity *> entities_;
};

#endif // WORLD_H