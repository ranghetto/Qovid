#ifndef ACTORS_LOGGER_H
#define ACTORS_LOGGER_H

#include "../Entities/Actor.h"
#include <QDateTime>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QVector2D>

class ActorsLogger {
public:
  ActorsLogger(int seed, int totalPopulation, int infectionRange,
               int infectionRateo, int deathChance, int infectionDuration,
               int initialInfectedPeople);

  void createLogData(int ID, int time, QVector2D position,
                     ActorHealthState oldState, ActorHealthState currentState);

  bool save() const;

private:
  class LogData {
  public:
    LogData(int ID, int time, QVector2D position, ActorHealthState oldState,
            ActorHealthState currentState);
    int ID;
    int time;
    QVector2D position;
    ActorHealthState oldState;
    ActorHealthState currentState;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
  };

  QString name_;
  QDateTime dateTime_;
  int seed_;
  int totalPopulation_;
  int infectionRange_;
  int infectionRateo_;
  int deathChance_;
  int infectionDuration_;
  int initialInfectedPeople_;
  QVector<LogData> data_;

  void read(const QJsonObject &json);
  void write(QJsonObject &json) const;
};

#endif // ACTORS_LOGGER_H