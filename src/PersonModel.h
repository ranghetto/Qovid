#ifndef PERSON
#define PERSON

class ActionAbstractModel;

#include <QPainter>
#include <QPoint>
#include <QVector2D>

class PersonModel : public QObject {
  Q_OBJECT
public:
  enum Status {
    Healthy,
    Infected,
    Recovered,
    Death,
  };

  // position: initial position, does not check boundaries, if any;
  // speed: initial speed as a QVector2D;
  // acceleration: initial acceleration as QVector2D;
  explicit PersonModel(QPointF position, QVector2D speed = QVector2D(0, 0),
                       QVector2D acceleration = QVector2D(0, 0),
                       Status status = Status::Healthy);

  // method to implement the way the object is drawn
  virtual void draw(QPainter &painter);

  virtual ~PersonModel();

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
  void setStatus(Status status);

  // getters
  QPointF getPosition() const;
  QVector2D getSpeed() const;
  QVector2D getAcceleration() const;
  ActionAbstractModel &getCurrentAction() const;
  Status getStatus() const;

private:
  QPointF position;
  QVector2D speed;
  QVector2D acceleration;
  ActionAbstractModel *currentAction;
  unsigned int speedLimit;
  Status status;
  unsigned int infectionRadius; // pixels
  unsigned int infectionRateo;  // %
  unsigned int deathRateo;      // %
};

#endif // PERSON