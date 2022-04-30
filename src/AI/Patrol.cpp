#include "Patrol.h"
#include "../Controllers/Simulation.h"

Patrol::Patrol(Actor &actor, QVector<QVector2D> waypoints, uint waitTime)
    : actor_(actor), waypoints_(waypoints), currentWaypointIndex_(0),
      waitTime_(waitTime), waitCounter_(0), waiting_(false) {}

NodeState Patrol::evaluate() {
  QVector2D currentWaypoint = waypoints_[currentWaypointIndex_];

  if (waiting_) {
    waitCounter_ += Simulation::instance().deltaTime();
    if (waitCounter_ >= waitTime_)
      waiting_ = false;
  } else {
    // The acceptance threshold, to check if the actor is arrived or not,
    // is the minimum distance it can travel: `actor_.speed() * deltaTime`
    if ((actor_.position() - currentWaypoint).length() <
        actor_.speed() * Simulation::instance().deltaTime()) {

      // adjust position
      actor_.setPosition(currentWaypoint);

      // start waiting
      waitCounter_ = 0;
      waiting_ = true;

      // if it has arrived, cycle through the next waypoint
      currentWaypointIndex_ = (currentWaypointIndex_ + 1) % waypoints_.length();
    } else {
      QVector2D direction = currentWaypoint - actor_.position();
      direction.normalize();
      direction *= actor_.speed() * Simulation::instance().deltaTime();

      actor_.setPosition(actor_.position() + direction);
    }
  }

  state_ = NodeState::RUNNING;
  return state_;
}