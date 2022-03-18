#ifndef ACTION_REACH_POINT_MODEL_H
#define ACTION_REACH_POINT_MODEL_H

#include "ActionAbstractModel.h"
#include <QPoint>

class ActionReachPointModel : public ActionAbstractModel {
public:
  ActionReachPointModel(PersonModel &person, QPointF destination,
                        unsigned int timeout = 0);
  void operator()() override;

private:
  QPointF destination;
};

#endif // ACTION_REACH_POINT_MODEL_H