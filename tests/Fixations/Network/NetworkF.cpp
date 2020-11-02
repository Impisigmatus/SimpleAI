#include <Network/NetworkF.hpp>

void NetworkF::SetUp()
{
  weights.push_back({
    1.1, 1.2, 1.3, 1.4, // 1 слой 1 нейрон => 4 нейрона 2 слоя
    2.1, 2.2, 2.3, 2.4  // 1 слой 2 нейрон => 4 нейрона 2 слоя
  });
  weights.push_back({
    1.1, 1.2, // 2 слой 1 нейрон => 2 нейрона 3 слоя
    2.1, 2.2, // 2 слой 2 нейрон => 2 нейрона 3 слоя
    3.1, 3.2, // 2 слой 3 нейрон => 2 нейрона 3 слоя
    4.1, 4.2  // 2 слой 4 нейрон => 2 нейрона 3 слоя
  });
}

bool NetworkF::listsEquals(const SimpleAI::List& first, const SimpleAI::List& second)
{
  const auto doubleEquals = [](const double& a, const double& b, const double& delta = 0.000001) {
    return std::abs(a - b) < delta;
  };

  if (first.size() != second.size())
    return false;

  for (size_t i = 0; i < first.size(); i++)
    if (!doubleEquals(first[i], second[i]))
      return false;
  return true;
}
