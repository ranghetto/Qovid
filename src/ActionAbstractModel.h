#ifndef ACTION_ABSTRACT_MODEL_H
#define ACTION_ABSTRACT_MODEL_H

class PersonModel;

class ActionAbstractModel {
public:
  ActionAbstractModel(unsigned int timeout = 0);

  virtual void operator()(PersonModel &person) = 0;

  bool getIsRunning() const;
  unsigned int getTimeout() const;

  void setIsRunning(bool isRunning);

private:
  unsigned int timeout;
  bool isRunning;
};

#endif // ACTION_ABSTRACT_MODEL_H