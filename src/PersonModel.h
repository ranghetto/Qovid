#ifndef PERSON
#define PERSON

class ActionAbstractModel;

#include <QPainter>
#include <QPoint>
#include <QVector2D>

class PersonModel : public QObject {
  Q_OBJECT
public:
  // position: initial position, does not check boundaries, if any;
  // speed: initial speed as a QVector2D;
  // acceleration: initial acceleration as QVector2D;
  explicit PersonModel(QPointF position, QVector2D speed = QVector2D(0, 0),
                       QVector2D acceleration = QVector2D(0, 0));

  // method to implement the way the object is drawn
  virtual void draw(QPainter &painter);

  // perform given action, if any;
  void doAction();

  // check speedlimit and adapt it, must be used after setSpeed() to affect
  // speed correctly
  void limitSpeed(float speedLimit);

  // setters
  void setPosition(QPointF position);
  void setSpeed(QVector2D speed);
  void setAcceleration(QVector2D acceleration);
  void setAction(ActionAbstractModel &action);

  // getters
  QPointF getPosition() const;
  QVector2D getSpeed() const;
  QVector2D getAcceleration() const;
  ActionAbstractModel &getCurrentAction() const;

private:
  QPointF position;
  QVector2D speed;
  QVector2D acceleration;
  ActionAbstractModel *currentAction;
  unsigned int speedLimit;
};

#endif // PERSON