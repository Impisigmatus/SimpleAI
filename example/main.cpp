#include <Teacher.hpp>

#include <SimpleAI/Utilities.hpp>

int main()
{
  const std::string PATH   = "example_network";
  SimpleAI::Matrix weights = SimpleAI::Utilities::deserialize(PATH);
  if (weights.empty())
    weights = SimpleAI::Utilities::makeMatrix({ 2, 4, 2 });

  Teacher teacher(300, 30, 1);
  auto network = teacher.teach(weights);
  SimpleAI::Utilities::serialize(network->getWeights(), PATH);
}
