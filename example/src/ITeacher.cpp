#include <ITeacher.hpp>

#include <iostream>

ITeacher::ITeacher(const size_t& iterations, const size_t& population, const double& step)
  : M_ITERATIONS (iterations)
  , M_POPULATION (population)
  , M_STEP       (step)
{}

std::shared_ptr<INetwork> ITeacher::teach(Matrix weights) const
{
  Student best;

  for (size_t i = 0; i < M_ITERATIONS; i++)
  {
    auto population = getPopulation(weights);

    for (const auto& student : population)
      if (student.grade > best.grade)
        best = student;

    weights = best.network->getWeights();

    if (i % 1000 == 0)
    {
      std::cout << i / 1000 + 1 << ") ";
          log(best);
    }
  }

  return best.network;
}