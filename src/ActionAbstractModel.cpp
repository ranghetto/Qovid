#include "ActionAbstractModel.h"

ActionAbstractModel::ActionAbstractModel(unsigned int timeout)
    : timeout(timeout), isRunning(true) {}

bool ActionAbstractModel::getIsRunning() const { return isRunning; }

unsigned int ActionAbstractModel::getTimeout() const { return timeout; }

void ActionAbstractModel::setIsRunning(bool isRunning) {
  this->isRunning = isRunning;
}
