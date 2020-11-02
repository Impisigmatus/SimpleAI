#include <Teacher.hpp>

#include <SimpleAI/Network.hpp>
#include <SimpleAI/Utilities.hpp>

#include <iostream>

Teacher::Teacher(const size_t& iterations, const size_t& population, const double& step)
  : ITeacher (iterations, population, step)
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
