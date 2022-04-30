#include "ActorsLogger.h"

ActorsLogger::ActorsLogger(int seed, int totalPopulation, int infectionRange,
                           int infectionRateo, int deathChance,
                           int infectionDuration, int initialInfectedPeople)
    : seed_(seed), totalPopulation_(totalPopulation),
      infectionRange_(infectionRange), infectionRateo_(infectionRateo),
      deathChance_(deathChance), infectionDuration_(infectionDuration),
      initialInfectedPeople_(initialInfectedPeople) {}

ActorsLogger::LogData::LogData(int ID, int time, QVector2D position,
                               ActorHealthState oldState,
                               ActorHealthState currentState)
    : ID(ID), time(time), position(position), oldState(oldState),
      currentState(currentState) {}

void ActorsLogger::createLogData(int ID, int time, QVector2D position,
                                 ActorHealthState oldState,
                                 ActorHealthState currentState) {
  data_.append(LogData(ID, time, position, oldState, currentState));
}

bool ActorsLogger::save() const {
  QFile file("name_.json");
  if (!file.open(QIODevice::WriteOnly))
    return false;

  QJsonObject simulation;
  write(simulation);
  file.write(QJsonDocument(simulation).toJson());
  return true;
}

void ActorsLogger::LogData::write(QJsonObject &json) const {
  json["id"] = ID;
  json["time"] = time;
  json["x"] = position.toPoint().x();
  json["y"] = position.toPoint().y();
  json["oldState"] = oldState;
  json["currentState"] = currentState;
}

void ActorsLogger::write(QJsonObject &json) const {
  json["name"] = name_;
  json["date_time"] = dateTime_.toString();
  json["seed"] = seed_;
  json["total_population"] = totalPopulation_;
  json["infection_range"] = infectionRange_;
  json["death_change"] = deathChance_;
  json["infection_duration"] = infectionDuration_;
  json["initial_infected_people"] = initialInfectedPeople_;

  QJsonArray dataArray;
  for (const LogData &log : data_) {
    QJsonObject logData;
    log.write(logData);
    dataArray.append(logData);
  }
  json["data"] = dataArray;
}