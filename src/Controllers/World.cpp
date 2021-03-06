#include "World.h"
#include "../Entities/Actor.h"
#include <QTime>
#include <QVector2D>

World::World(Simulation &s, uint population, uint infection_range,
             uint infection_rate, uint death_rate, uint time_toRecover,
             uint initial_infect) {

  for (uint j = 0; j < population; j++) {
    QVector<QVector2D> v;
    for (uint i = 0; i < 6; i++) {
      v.append(QVector2D(qrand() % 500, qrand() % 500));
    }
    Actor *a = new Actor(s, v[0], 0.1f, ActorHealthState::HEALTHY,
                         {v[1], v[2], v[3], v[4], v[5]}, 2000, infection_range,
                         time_toRecover * 1000, death_rate, infection_rate);
    if (population - initial_infect <= j) {
      a->setHealthState(ActorHealthState::INFECTED);
    }
    addEntity(*a);
  }
}

QVector<Entity *> World::entities() const { return entities_; }

int World::infectedCount() const {
  int i = 0;
  for (auto e : entities_) {
    Actor *a = dynamic_cast<Actor *>(e);
    if (a && a->healthState() == ActorHealthState::INFECTED)
      i++;
  }
  return i;
}

int World::actorsCount() const {
  int i = 0;
  for (auto e : entities_) {
    Actor *a = dynamic_cast<Actor *>(e);
    if (a)
      i++;
  }
  return i;
}

void World::addEntity(Entity &entity) { entities_.append(&entity); }

QVector<Actor *> World::findNearbyActors(QVector2D center, int range) const {
  QVector<Actor *> list;
  for (auto e : entities_) {
    Actor *a = dynamic_cast<Actor *>(e);
    if (a)
      if ((center - a->position()).length() <= range)
        list.append(a);
  }
  return list;
}

World::~World() {
  for (auto e : entities_)
    delete e;
}