#include "ActionAbstractModel.h"

ActionAbstractModel::ActionAbstractModel(PersonModel &person,
                                         unsigned int timeout)
    : person(person), timeout(timeout), isRunning(true) {}

bool ActionAbstractModel::getIsRunning() const { return isRunning; }

PersonModel &ActionAbstractModel::getPerson() const { return person; }

unsigned int ActionAbstractModel::getTimeout() const { return timeout; }

void ActionAbstractModel::setIsRunning(bool isRunning) {
  this->isRunning = isRunning;
}
