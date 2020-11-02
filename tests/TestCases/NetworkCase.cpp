#include <Network/NetworkF.hpp>

#include <SimpleAI/Network.hpp>

TEST_F(NetworkF, Valid)
{
  // Инициализация значений
  SimpleAI::List inputs   = { 1, 0.5 };
  SimpleAI::List expected = { 25.45, 26.4 };

  // Выполнение
  SimpleAI::Network network(weights, [](const double& x) -> double { return x; });
  auto outputs = network.exec(inputs);

  // Проверка
  ASSERT_EQ(outputs.size(), expected.size());
  for (size_t i = 0; i < outputs.size(); i++)
    EXPECT_TRUE(doubleEQ(outputs[i], expected[i]));
}
