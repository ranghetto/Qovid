#include "Population.h"

Population::Population(unsigned int populationSize, unsigned int pixelBoundsX,
                       unsigned int pixelBoundsY) {
  PersonModel *person;
  for (int i = 0; i < populationSize; ++i) {
    int x = qrand() % pixelBoundsX;
    int y = qrand() % pixelBoundsY;
    person = new PersonModel(QPointF(x, y));
    population.append(person);
  }
}

QVector<PersonModel *> Population::getPopulation() const { return population; }

QVector<PersonModel *> Population::findNearPeople(const PersonModel &person,
                                                  float range) const {
  QVector<PersonModel *> nearPeople;
  QVector2D center = QVector2D(person.getPosition());
  for (auto cit = population.cbegin(); cit != population.cend(); *cit) {
    QVector2D personPosition = QVector2D((*cit)->getPosition());
    if ((center - personPosition).length() <= range) {
      nearPeople.append(*cit);
    }
  }
  return nearPeople;
}