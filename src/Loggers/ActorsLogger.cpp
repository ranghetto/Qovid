#include "ActorsLogger.h"
#include <stdexcept>

ActorsLogger::ActorsLogger(int seed, int totalPopulation, int infectionRange,
                           int infectionRateo, int deathRateo,
                           int infectionDuration, int initialInfectedPeople)
    : dateTime_(QDateTime::currentDateTime()),
      name_(dateTime_.toString(Qt::ISODate)), seed_(seed),
      totalPopulation_(totalPopulation), infectionRange_(infectionRange),
      infectionRateo_(infectionRateo), deathRateo_(deathRateo),
      infectionDuration_(infectionDuration),
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

bool ActorsLogger::save(const QString &url) const {
  QFile file(url + ".json");
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
  json["date_time"] = dateTime_.toString(Qt::ISODate);
  json["seed"] = seed_;
  json["total_population"] = totalPopulation_;
  json["infection_range"] = infectionRange_;
  json["death_rateo"] = deathRateo_;
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

ActorsLogger::ActorsLogger(const QJsonObject &json) {
  if (json.contains("name") && json["name"].isString())
    name_ = json["name"].toString();
  if (json.contains("date_time") && json["date_time"].isString())
    dateTime_ = QDateTime::fromString(json["date_time"].toString());
  if (json.contains("seed") && json["seed"].isDouble())
    seed_ = json["seed"].toInt();
  if (json.contains("total_population") && json["total_population"].isDouble())
    totalPopulation_ = json["total_population"].toInt();
  if (json.contains("infection_range") && json["infection_range"].isDouble())
    infectionRange_ = json["infection_range"].toInt();
  if (json.contains("death_rateo") && json["death_rateo"].isDouble())
    deathRateo_ = json["death_rateo"].toInt();
  if (json.contains("infection_duration") &&
      json["infection_duration"].isDouble())
    infectionDuration_ = json["infection_duration"].toInt();
  if (json.contains("initial_infected_people") &&
      json["initial_infected_people"].isDouble())
    initialInfectedPeople_ = json["initial_infected_people"].toInt();

  if (json.contains("data") && json["data"].isArray()) {
    QJsonArray dataArray = json["data"].toArray();
    data_.clear();
    data_.reserve(dataArray.size());
    for (int i = 0; i < dataArray.size(); ++i) {
      QJsonObject logObj = dataArray[i].toObject();
      LogData logData(logObj);
      data_.append(logData);
    }
  }
}

ActorsLogger::LogData::LogData(const QJsonObject &json) {
  if (json.contains("id") && json["id"].isDouble())
    ID = json["id"].toInt();
  if (json.contains("time") && json["time"].isDouble())
    time = json["time"].toInt();
  if (json.contains("x") && json["x"].isDouble())
    position.setX(json["x"].toDouble());
  if (json.contains("y") && json["y"].isDouble())
    position.setX(json["y"].toDouble());
  if (json.contains("oldState") && json["oldState"].isDouble())
    // Add try-catch so in the future we can show an error widget
    try {
      oldState = Actor::healthState(json["oldState"].toInt());
    } catch (ActorHealhStateUndefined) {
      throw std::invalid_argument("cannot convert " +
                                  json["oldState"].toString().toStdString() +
                                  "to ActorHealthState.");
    }
  if (json.contains("currentState") && json["currentState"].isDouble())
    // Add try-catch so in the future we can show an error widget
    try {
      currentState = Actor::healthState(json["currentState"].toInt());
    } catch (ActorHealhStateUndefined) {
      throw std::invalid_argument(
          "cannot convert " + json["currentState"].toString().toStdString() +
          "to ActorHealthState.");
    }
}