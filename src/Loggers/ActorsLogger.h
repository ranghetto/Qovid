#ifndef ACTORS_LOGGER_H
#define ACTORS_LOGGER_H

#include "../Entities/Actor.h"
#include <QDateTime>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QString>
#include <QVector2D>

class ActorsLogger {
public:
  ActorsLogger(const QString &name, const QDateTime &dateTime, int seed,
               int totalPopulation, int infectionRange, int infectionRateo,
               int deathChance, int infectionDuration,
               int initialInfectedPeople);
  ActorsLogger(const QJsonObject &json);

  void createInfectionData(int time, QVector2D position);
  void updateStatusCounters(int time, ActorHealthState old,
                            ActorHealthState current);

  bool save(const QString &url) const;
  void write(QJsonObject &json) const;

  QString getName() const;

  ~ActorsLogger();

private:
  class Infection {
  public:
    Infection(int time, QVector2D position);
    Infection(const QJsonObject &json);
    int time;
    QVector2D position;

    void write(QJsonObject &json) const;
  };
  class Moment {
  public:
    Moment(int healthy);
    Moment(const QJsonObject &json);
    void advance(int time);
    int time;
    int healthy;
    int infected;
    int recovered;
    int dead;

    void write(QJsonObject &json) const;
  };

  QDateTime dateTime_;
  QString name_;
  int seed_;
  int totalPopulation_;
  int infectionRange_;
  int infectionRateo_;
  int deathRateo_;
  int infectionDuration_;
  int initialInfectedPeople_;

  QList<Infection> infections_;
  QList<Moment *> moments_;
};

#endif // ACTORS_LOGGER_H