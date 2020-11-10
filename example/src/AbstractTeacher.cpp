#include <AbstractTeacher.hpp>

#include <SimpleAI/Network.hpp>

#include <iostream>

AbstractTeacher::AbstractTeacher(const size_t& iterations,
                                 const size_t& population,
                                 const double& step)
  : M_ITERATIONS (iterations)
  , M_POPULATION (population)
  , M_STEP       (step)
{}

std::shared_ptr<AbstractNetwork> AbstractTeacher::teach(Matrix weights) const
{
  Student best;
  best.network.reset(new Network(weights, mActivation));
  best.grade = grading(best.network);

  double step = M_STEP;
  for (size_t i = 0; i < M_ITERATIONS; i++)
  {
    auto bestOfGen = getBest(weights, step);
    if (bestOfGen.grade > best.grade)
    {
      best = bestOfGen;
      step = M_STEP;
      std::cout << "Найден уникум " << best.grade * 100 << '%' << std::endl;
    }
    else
      step += 0.1;

    weights = best.network->getWeights();
  }

  return best.network;
}

Student AbstractTeacher::getBest(const Matrix& weights, const double& step) const
{
  Students students(M_POPULATION);

  Student best;
  for (auto& student : students)
  {
    student.network = makeNetwork(weights, step);
    student.grade = grading(student.network);
    if (student.grade > best.grade)
      best = student;
  }
  return best;
}
