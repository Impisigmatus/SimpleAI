#include <Teacher.hpp>

#include <SimpleAI/Network.hpp>
#include <SimpleAI/Utilities.hpp>

#include <iostream>

Teacher::Teacher(const Matrix&              inputs,
                 const std::vector<size_t>& answers,
                 const size_t&              iterations,
                 const size_t&              population,
                 const double&              step)
  : AbstractTeacher (iterations, population, step)
  , mInputs  (inputs)
  , mAnswers (answers)
{
  mActivation = [](const double& x) {
    return 1 / (1 + exp(-x));
  };
}

std::shared_ptr<AbstractNetwork> Teacher::makeNetwork(
    const Matrix& weights, const double& step) const
{
  return std::make_shared<Network>(mutate(weights, step), mActivation);
}

double Teacher::grading(const std::shared_ptr<AbstractNetwork>& network) const
{
  const auto gradingOutputs = [](const List& outputs, const size_t& answer) -> double {
    double sum = 0;
    for (const auto& output : outputs)
      sum += output;
    return outputs[answer]/sum;
  };

  double grade = 0;
  for (size_t i = 0; i < mInputs.size(); i++)
    grade += gradingOutputs(network->exec(mInputs[i]), mAnswers[i]);
  grade /= mInputs.size();
  return grade;
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
