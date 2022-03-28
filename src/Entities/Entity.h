#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QtGlobal>

class Entity {
public:
  Entity() = default;
  virtual ~Entity() = default;

  virtual void update(qint64 deltaTime) = 0;
  virtual void render(QPainter &painter) = 0;
};

#endif // ENTITY_H