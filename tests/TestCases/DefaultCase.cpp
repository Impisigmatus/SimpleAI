#include <gtest/gtest.h>

#include <SimpleAI/Network.hpp>

TEST(DefaultCase, Test)
{
  SimpleAI::List inputs  = { 1, 0.5 };
  SimpleAI::Matrix weights;
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

  SimpleAI::Network network(weights, [](const double& x) -> double { return x; });
  auto outputs = network.exec(inputs);

  SimpleAI::List expected = { 25.45, 26.4 };
  EXPECT_EQ(outputs, expected);
}
