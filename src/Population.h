#ifndef POPULATION_H
#define POPULATION_H

#include "ActionAbstractModel.h"
#include "PersonModel.h"

#include <QVector>

// Container class
class Population {
public:
  // generate a new population of size "populationSize", single person's
  // position is choosen pseduo randomically in a the given bounds:
  // 0 to X and 0 to Y (since widgets pixels are relative to itself)
  Population(unsigned int populationSize, unsigned int pixelBoundsX,
             unsigned int pixelBoundsY);

  // return all people in a range from passed person's position
  // passed person is not included
  QVector<PersonModel *> findNearPeople(const PersonModel &person,
                                        float range) const;

  // return whole population
  QVector<PersonModel *> getPopulation() const;

private:
  QVector<PersonModel *> population;
};

#endif // POPULATION_H