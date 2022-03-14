#ifndef ACTION
#define ACTION

class PersonModel;

class ActionAbstractModel {
public:
  ActionAbstractModel(PersonModel &person, unsigned int timeout = 0);
  virtual void operator()() = 0;

protected:
  bool isRunning;
  PersonModel &person;
  unsigned int timeout;
};

#endif // ACTION