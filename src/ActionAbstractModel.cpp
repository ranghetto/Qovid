#include "ActionAbstractModel.h"

ActionAbstractModel::ActionAbstractModel(PersonModel &person,
                                         unsigned int timeout)
    : person(person), timeout(timeout), isRunning(true) {}