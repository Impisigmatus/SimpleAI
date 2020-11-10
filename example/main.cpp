#include <Teacher.hpp>

#include <SimpleAI/Utilities.hpp>

#include <iostream>

int main()
{
  // Исходные данные
  const std::string PATH   = "example_network";
  SimpleAI::Matrix inputs = {
    { 0, 0 },
    { 0, 1 },
    { 1, 0 },
    { 1, 1 },
  };
  std::vector<size_t> answers = { 1, 0, 0, 1 };

  // Создание матрицы
  SimpleAI::Matrix weights = SimpleAI::Utilities::deserialize(PATH);
  if (weights.empty())
    weights = SimpleAI::Utilities::makeMatrix({ 2, 4, 2 });

  // Обучение
  Teacher teacher(inputs, answers, 100, 30, 1);
  auto network = teacher.teach(weights);
  SimpleAI::Utilities::serialize(network->getWeights(), PATH);

  // Вывод результатов работы
  const auto toString = [](const List& input) {
    std::string result = "{ ";
    for (size_t i = 0; i < input.size(); i++)
      result += std::to_string(static_cast<int>(input[i]))
             +  (i+1 == input.size() ? " }" : ", ");
    return result;
  };

  for (const auto& input : inputs)
  {
    auto data = network->exec(input);
    std::cout << toString(input) << " = " << (data[0] > data[1] ? 0 : 1) << std::endl;
  }
}
