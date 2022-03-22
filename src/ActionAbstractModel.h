#ifndef ACTION_ABSTRACT_MODEL_H
#define ACTION_ABSTRACT_MODEL_H

class PersonModel;

class ActionAbstractModel {
public:
  // Accept a positive value as timeout that rappresents seconds before the
  // action, if not stopped before, will be considered out of timed and set as
  // finished.
  ActionAbstractModel(unsigned int timeout = 0);

  // Function that every subclass need to implement, takes in input a
  // PersonModel and it handles the logic for the specific action, executed by
  // the single person.
  virtual void operator()(PersonModel &person) = 0;

  // true, action is not finished yet;
  // false, action could be finished or timeoutted.
  bool getIsRunning() const;
  // return timeout (total, not remaning);
  // TODO could be much usefull to return remaining time too.
  unsigned int getTimeout() const;

  virtual ~ActionAbstractModel() = default;

  void setIsRunning(bool isRunning);

private:
  unsigned int timeout;
  bool isRunning;
};

#endif // ACTION_ABSTRACT_MODEL_H