#ifndef ACTION_REACH_POINT_MODEL_H
#define ACTION_REACH_POINT_MODEL_H

#include "ActionAbstractModel.h"
#include <QPoint>

class ActionReachPointModel : public ActionAbstractModel {
public:
  // implements a QPointF as destination for the PersonModel, it does not handle
  // boundaries, any point is valid;
  ActionReachPointModel(QPointF destination, unsigned int timeout = 0);
  void operator()(PersonModel &person) override;

private:
  QPointF destination;
};

#endif // ACTION_REACH_POINT_MODEL_H