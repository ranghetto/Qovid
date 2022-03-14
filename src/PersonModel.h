#ifndef PERSON
#define PERSON

class ActionAbstractModel;

#include <QPainter>
#include <QPoint>
#include <QRandomGenerator>
#include <QVector2D>

class PersonModel : public QObject {
  Q_OBJECT
public:
  explicit PersonModel(QPoint position, QVector2D speed = QVector2D(0, 0),
                       QVector2D acceleration = QVector2D(0, 0),
                       QPoint bounds = QPoint(500, 500));

  virtual void draw(QPainter &painter);
  void doAction();

  // setters
  void setPosition(QPoint position);
  void setSpeed(QVector2D speed);
  void setAcceleration(QVector2D acceleration);
  void setBounds(QPoint bounds);
  void setAction(ActionAbstractModel &action);
  void limitSpeed(unsigned int speedLimit);

  // getters
  QPoint getPosition() const;
  QVector2D getSpeed() const;
  QVector2D getAcceleration() const;
  QPoint getBounds() const;
  ActionAbstractModel &getCurrentAction() const;

private:
  QPoint position;
  QVector2D speed;
  QVector2D acceleration;
  QPoint bounds;
  ActionAbstractModel *currentAction;
  unsigned int speedLimit;
};

#endif // PERSON