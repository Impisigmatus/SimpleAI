#include <Teacher.hpp>
#include <Network.hpp>
#include <Utilities.hpp>

#include <iostream>

namespace SimpleAI {

Teacher::Teacher(const size_t& iterations, const size_t& population, const double& step)
  : M_ITERATIONS (iterations)
  , M_POPULATION (population)
  , M_STEP       (step)
{
  mActivation = [](const double& x) {
    return 1 / (1 + exp(-x*10+5));
  };

  mInputs = {
    { 0, 0 },
    { 0, 1 },
    { 1, 0 },
    { 1, 1 },
  };

  mAnswers = { 1, 0, 0, 1};
}

std::shared_ptr<INetwork> Teacher::teach(Matrix weights) const
{
  Student best;

  for (size_t i = 0; i < M_ITERATIONS; i++)
  {
    auto population = getPopulation(weights);
    for (const auto& student : population)
    {
      if (student.grade > best.grade)
        best = student;
    }
    weights = best.network->getWeights();

    if (i % 1000 == 0)
    {
      std::cout << i / 10000 << ") ";
          log(best);
    }
  }

  return best.network;
}

Students Teacher::getPopulation(const Matrix& weights) const
{
  Students population(M_POPULATION);

  for (auto& student : population)
  {
    student.network.reset(new Network(Utilities::mutate(weights, M_STEP), mActivation));
    for (size_t i = 0; i < mInputs.size(); i++)
      student.grade += grading(student.network->exec(mInputs[i]), mAnswers[i]);
    student.grade /= mInputs.size();
  }

  return population;
}

double Teacher::grading(const List& outputs, const size_t& answer) const
{
  double sum = 0;
  for (const auto& output : outputs)
    sum += output;
  if (sum == 0.0)
    return 0;
  return outputs[answer]/sum;
}

void Teacher::log(const Student& student) const
{
  std::cout << "Лучший студент: " << student.grade*100 << "%" << std::endl;

  List data;
  data = student.network->exec({ 0, 0 });
  std::cout << "{ 0, 0 } = " << (data[0] > data[1] ? 0 : 1) << std::endl;
  data = student.network->exec({ 1, 0 });
  std::cout << "{ 1, 0 } = " << (data[0] > data[1] ? 0 : 1) << std::endl;
  data = student.network->exec({ 0, 1 });
  std::cout << "{ 0, 1 } = " << (data[0] > data[1] ? 0 : 1) << std::endl;
  data = student.network->exec({ 1, 1 });
  std::cout << "{ 1, 1 } = " << (data[0] > data[1] ? 0 : 1) << std::endl;
}

} // namespace SimpleAI
