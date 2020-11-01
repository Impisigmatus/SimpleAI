#include <gtest/gtest.h>

#include <SimpleAI/Network.hpp>

TEST(DefaultCase, Test)
{
  SimpleAI::Network network;
  auto outputs = network.exec({});
  EXPECT_TRUE(outputs.empty());
}
