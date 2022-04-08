#include "World.h"
#include "../Entities/Actor.h"
#include <QTime>
#include <QVector2D>

World::World(int population): population_(population) {
  qsrand(QTime::currentTime().msec());

  for (int j = 0; j < population_; j++) {
    QVector<QVector2D> v;
    for (int i = 0; i < 5; i++) {
      v.append(QVector2D(qrand() % 500, qrand() % 500));
    }
    Actor *a = new Actor({v[0], v[1], v[2], v[3], v[4]}, v[0], 0.2f);
    addEntity(*a);
  }
}

QVector<Entity *> World::entities() const { return entities_; }

void World::addEntity(Entity &entity) { entities_.append(&entity); }