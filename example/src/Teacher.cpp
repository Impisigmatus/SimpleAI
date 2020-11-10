#include <Teacher.hpp>

#include <SimpleAI/Network.hpp>
#include <SimpleAI/Utilities.hpp>

#include <iostream>

Teacher::Teacher(const size_t& iterations, const size_t& population, const double& step)
  : AbstractTeacher (iterations, population, step)
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
  mAnswers = { 1, 0, 0, 1 };
}

Students Teacher::getPopulation(const Matrix& weights, const double& step) const
{
  Students population(M_POPULATION);

  for (auto& student : population)
  {
    student.network.reset(new Network(mutate(weights, step), mActivation));
    student.grade = grading(student.network);
  }

  return population;
}

double Teacher::grading(const std::shared_ptr<AbstractNetwork>& network) const
{
  const auto gradingOutput = [](const List& outputs, const size_t& answer) -> double {
    double sum = 0;
    for (const auto& output : outputs)
      sum += output;
    return outputs[answer]/sum;
  };

  double grade = 0;
  for (size_t i = 0; i < mInputs.size(); i++)
    grade += gradingOutput(network->exec(mInputs[i]), mAnswers[i]);
  grade /= mInputs.size();
  return grade;
}

void Teacher::log(const Student& student, const size_t& i) const
{
  size_t part = M_ITERATIONS;
  if (part > 10)
    part /= 10;

  if (i % part != 0)
    return;

  const auto toString = [](const List& input) {
    std::string result = "{ ";
    for (size_t i = 0; i < input.size(); i++)
      result += std::to_string(static_cast<int>(input[i]))
             +  (i+1 == input.size() ? " }" : ", ");
    return result;
  };

  std::cout << i / part + 1 << ") " << student.grade*100 << "% обученнности" << std::endl;

  for (const auto& input : mInputs)
  {
    auto data = student.network->exec(input);
    std::cout << toString(input) << " = " << (data[0] > data[1] ? 0 : 1) << std::endl;
  }
}

Matrix Teacher::mutate(Matrix matrix, const double& step) const
{
  for (auto& list : matrix)
  {
    for (auto& weight : list)
    {
      switch (Utilities::rand(1, 3))
      {
        case 1:
          weight += step;
          break;
        case 2:
          weight -= step;
          break;
        default:
          break;
      }
    }
  }

  return matrix;
}
