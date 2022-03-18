#ifndef ACTION_ABSTRACT_MODEL_H
#define ACTION_ABSTRACT_MODEL_H

class PersonModel;
class QPainter;

class ActionAbstractModel {
public:
  ActionAbstractModel(PersonModel &person, unsigned int timeout = 0);
  virtual void operator()() = 0;
  bool getIsRunning() const;
  PersonModel &getPerson() const;
  unsigned int getTimeout() const;

  void setIsRunning(bool isRunning);

private:
  PersonModel &person;
  unsigned int timeout;
  bool isRunning;
};

#endif // ACTION_ABSTRACT_MODEL_H