#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QtGlobal>

// Incomplete type
class Simulation;

class Entity {
public:
  Entity() = default;
  virtual ~Entity() = default;

  virtual void update(const Simulation &s) = 0;
  virtual void render(QPainter &painter) = 0;
};

#endif // ENTITY_H