#include <Teacher.hpp>

#include <SimpleAI/Utilities.hpp>

int main()
{
  SimpleAI::Matrix weights;
  weights.push_back({
    0.5, 0.5, 0.5, 0.5, // 1 слой 1 нейрон => 4 нейрона 2 слоя
    0.5, 0.5, 0.5, 0.5  // 1 слой 2 нейрон => 4 нейрона 2 слоя
  });
  weights.push_back({
    0.5, 0.5, // 2 слой 1 нейрон => 2 нейрона 3 слоя
    0.5, 0.5, // 2 слой 2 нейрон => 2 нейрона 3 слоя
    0.5, 0.5, // 2 слой 3 нейрон => 2 нейрона 3 слоя
    0.5, 0.5  // 2 слой 4 нейрон => 2 нейрона 3 слоя
  });
  SimpleAI::Utilities::fillRand(weights);

  Teacher teacher(100000, 50, 0.1);
  auto network = teacher.teach(weights);
}