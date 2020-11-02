#include <Network/NetworkF.hpp>

#include <SimpleAI/Network.hpp>

TEST_F(NetworkF, Int)
{
  SimpleAI::List inputs   = { 1, 0 };
  SimpleAI::List expected = { 13.5, 14 };

  SimpleAI::Network network(weights, [](const double& x) -> double { return x; });
  auto outputs = network.exec(inputs);

  ASSERT_TRUE(listsEquals(outputs, expected));
}

TEST_F(NetworkF, Float)
{
  SimpleAI::List inputs   = { 0.5, 0.5 };
  SimpleAI::List expected = { 18.7, 19.4 };

  SimpleAI::Network network(weights, [](const double& x) -> double { return x; });
  auto outputs = network.exec(inputs);

  ASSERT_TRUE(listsEquals(outputs, expected));
}

TEST_F(NetworkF, OneNegative)
{
  SimpleAI::List inputs   = { 0.5, -0.5 };
  SimpleAI::List expected = { -5.2, -5.4 };

  SimpleAI::Network network(weights, [](const double& x) -> double { return x; });
  auto outputs = network.exec(inputs);

  ASSERT_TRUE(listsEquals(outputs, expected));
}

TEST_F(NetworkF, AllNegative)
{
  SimpleAI::List inputs   = { -0.5, -0.5 };
  SimpleAI::List expected = { -18.7, -19.4 };

  SimpleAI::Network network(weights, [](const double& x) -> double { return x; });
  auto outputs = network.exec(inputs);

  ASSERT_TRUE(listsEquals(outputs, expected));
}
