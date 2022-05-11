#include "ActorsLogger.h"

ActorsLogger::ActorsLogger(const QString &name, const QDateTime &dateTime,
                           int seed, int totalPopulation, int infectionRange,
                           int infectionRateo, int deathRateo,
                           int infectionDuration, int initialInfectedPeople)
    : dateTime_(dateTime), name_(name), seed_(seed),
      totalPopulation_(totalPopulation), infectionRange_(infectionRange),
      infectionRateo_(infectionRateo), deathRateo_(deathRateo),
      infectionDuration_(infectionDuration),
      initialInfectedPeople_(initialInfectedPeople) {
  moments_.append(new Moment(totalPopulation));
}

ActorsLogger::~ActorsLogger() {
  for (auto moment : moments_) {
    delete moment;
  }
}

QString ActorsLogger::getName() const { return name_; }

ActorsLogger::Moment::Moment(int healthy)
    : time(0), healthy(healthy), infected(0), recovered(0), dead(0) {}

ActorsLogger::Infection::Infection(int time, QVector2D position)
    : time(time), position(position) {}

void ActorsLogger::createInfectionData(int time, QVector2D position) {
  infections_.append(Infection(time, position));
}

void ActorsLogger::Moment::advance(int t) { time = t; }

void ActorsLogger::updateStatusCounters(int time, ActorHealthState old,
                                        ActorHealthState current) {
  Moment *m;
  bool add = false;
  if (time == moments_.last()->time)
    m = moments_.last();
  else {
    m = new Moment(*moments_.last());
    m->advance(time);
    add = true;
  }

  if (old == ActorHealthState::HEALTHY &&
      current == ActorHealthState::INFECTED) {
    m->healthy--;
    m->infected++;
  }
  if (old == ActorHealthState::INFECTED &&
      current == ActorHealthState::RECOVERED) {
    m->infected--;
    m->recovered++;
  }
  if (old == ActorHealthState::INFECTED && current == ActorHealthState::DEAD) {
    m->infected--;
    m->dead++;
  }

  if (add)
    moments_.append(m);
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

void ActorsLogger::Infection::write(QJsonObject &json) const {
  json["time"] = time;
  json["x"] = position.toPoint().x();
  json["y"] = position.toPoint().y();
}

void ActorsLogger::Moment::write(QJsonObject &json) const {
  json["time"] = time;
  json["healthy"] = healthy;
  json["infected"] = infected;
  json["recovered"] = recovered;
  json["dead"] = dead;
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

  QJsonArray infectionArray;
  for (const Infection &log : infections_) {
    QJsonObject inf;
    log.write(inf);
    infectionArray.append(inf);
  }
  json["infections"] = infectionArray;

  QJsonArray momentArray;
  for (const Moment *mom : moments_) {
    QJsonObject obj;
    mom->write(obj);
    momentArray.append(obj);
  }
  json["moments"] = momentArray;
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

  if (json.contains("infections") && json["infections"].isArray()) {
    QJsonArray dataArray = json["infections"].toArray();
    infections_.clear();
    infections_.reserve(dataArray.size());
    for (int i = 0; i < dataArray.size(); ++i) {
      QJsonObject logObj = dataArray[i].toObject();
      Infection inf(logObj);
      infections_.append(inf);
    }
  }
  if (json.contains("moments") && json["moments"].isArray()) {
    QJsonArray dataArray = json["moments"].toArray();
    moments_.clear();
    moments_.reserve(dataArray.size());
    for (int i = 0; i < dataArray.size(); ++i) {
      QJsonObject logObj = dataArray[i].toObject();
      Moment *mom = new Moment(logObj);
      moments_.append(mom);
    }
  }
}

ActorsLogger::Moment::Moment(const QJsonObject &json) {
  if (json.contains("time") && json["time"].isDouble())
    time = json["time"].toInt();
  if (json.contains("healthy") && json["healthy"].isDouble())
    time = json["healthy"].toInt();
  if (json.contains("infected") && json["infected"].isDouble())
    time = json["infected"].toInt();
  if (json.contains("recovered") && json["recovered"].isDouble())
    time = json["recovered"].toInt();
  if (json.contains("dead") && json["dead"].isDouble())
    time = json["dead"].toInt();
}

ActorsLogger::Infection::Infection(const QJsonObject &json) {
  if (json.contains("time") && json["time"].isDouble())
    time = json["time"].toInt();
  if (json.contains("x") && json["x"].isDouble())
    position.setX(json["x"].toDouble());
  if (json.contains("y") && json["y"].isDouble())
    position.setX(json["y"].toDouble());
}