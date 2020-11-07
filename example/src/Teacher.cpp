#include <Teacher.hpp>

#include <SimpleAI/Network.hpp>
#include <SimpleAI/Utilities.hpp>

#include <iostream>

Teacher::Teacher(const size_t& iterations, const size_t& population, const double& step)
  : ITeacher (iterations, population, step)
{
  mActivation = [](const double& x) {
    return 1 / (1 + exp(-x));
  };

  mInputs = {
    { 0, 0 },
    { 0, 1 },
    { 1, 0 },
    { 1, 1 },
  };
  mAnswers = { 1, 0, 0, 1};
}

Students Teacher::getPopulation(const Matrix& weights) const
{
  Students population(M_POPULATION);

  for (auto& student : population)
  {
    student.network.reset(new Network(mutate(weights, M_STEP), mActivation));
    student.grade = grading(student.network);
  }

  return population;
}

double Teacher::grading(const std::shared_ptr<INetwork>& network) const
{
  double grade = 0;
  for (size_t i = 0; i < mInputs.size(); i++)
    grade += grading(network->exec(mInputs[i]), mAnswers[i]);
  grade /= mInputs.size();
  return grade;
}

void Teacher::log(const Student& student) const
{
  std::cout << "Лучший студент: " << student.grade*100 << "%" << std::endl;

  List   data;
  size_t out;

  data = student.network->exec({ 0, 0 });
  out  = (data[0] > data[1] ? 0 : 1);
  std::cout << "{ 0, 0 } = " << out << std::endl;

  data = student.network->exec({ 1, 0 });
  out  = (data[0] > data[1] ? 0 : 1);
  std::cout << "{ 1, 0 } = " << out << std::endl;

  data = student.network->exec({ 0, 1 });
  out  = (data[0] > data[1] ? 0 : 1);
  std::cout << "{ 0, 1 } = " << out << std::endl;

  data = student.network->exec({ 1, 1 });
  out  = (data[0] > data[1] ? 0 : 1);
  std::cout << "{ 1, 1 } = " << out << std::endl;
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

Matrix Teacher::mutate(Matrix matrix, const double& step) const
{
  const auto shift = [](double& weight, const double& step) {
    weight += step;
  };

  for (auto& list : matrix)
  {
    for (auto& weight : list)
    {
      switch (Utilities::rand(1, 3))
      {
        case 1:
          shift(weight, step);
          break;
        case 2:
          shift(weight, -step);
          break;
        default:
          break;
      }
    }
  }

  return matrix;
}
