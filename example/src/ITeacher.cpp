#include <ITeacher.hpp>

#include <SimpleAI/Network.hpp>

#include <iostream>

ITeacher::ITeacher(const size_t& iterations, const size_t& population, const double& step)
  : M_ITERATIONS (iterations)
  , M_POPULATION (population)
  , M_STEP       (step)
{}

std::shared_ptr<INetwork> ITeacher::teach(Matrix weights) const
{
  Student best;
  best.network.reset(new Network(weights, mActivation));
  best.grade = grading(best.network);

  for (size_t i = 0; i < M_ITERATIONS; i++)
  {
    auto population = getPopulation(weights);

    for (const auto& student : population)
      if (student.grade > best.grade)
        best = student;

    weights = best.network->getWeights();

    const size_t LOG_GEN = 10;
    if (i % LOG_GEN == 0)
    {
      std::cout << i / LOG_GEN + 1 << ") ";
          log(best);
    }
  }

  return best.network;
}
