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

  double step = M_STEP;
  for (size_t i = 0; i < M_ITERATIONS; i++)
  {
    auto bestOfGen = getBest(getPopulation(weights, step));
    if (bestOfGen.grade > best.grade)
    {
      best = bestOfGen;
      step = M_STEP;
    }
    else
      step += 0.1;

    weights = best.network->getWeights();
    log(best, i);
  }

  return best.network;
}

Student ITeacher::getBest(const Students& students) const
{
  Student best;
  for (const auto& student : students)
    if (student.grade > best.grade)
      best = student;
  return best;
}
