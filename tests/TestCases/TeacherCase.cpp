#include <gtest/gtest.h>

#include <SimpleAI/Teacher.hpp>
#include <SimpleAI/Utilities.hpp>

TEST(TeacherCase, XOR)
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

  SimpleAI::Teacher teacher(10000, 20, 0.1);
  auto network = teacher.teach(weights);
}
