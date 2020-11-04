#include <gtest/gtest.h>

#include <SimpleAI/Utilities.hpp>

TEST(SerializationCase, Serialize)
{
  SimpleAI::Matrix weights;
  weights.push_back({
    1.1, 1.2, 1.3, 1.4,
    1.5, 1.6, 1.7, 1.8
  });
  weights.push_back({
    2.1, 2.2,
    2.3, 2.4,
    2.5, 2.6,
    2.7, 2.8
  });

  EXPECT_TRUE(SimpleAI::Utilities::serialize(weights, "network.txt"));
}

TEST(SerializationCase, Deserialize)
{
  SimpleAI::Matrix weights = SimpleAI::Utilities::deserialize("network.txt");
  SimpleAI::Matrix expected;
  expected.push_back({
    1.1, 1.2, 1.3, 1.4,
    1.5, 1.6, 1.7, 1.8
  });
  expected.push_back({
    2.1, 2.2,
    2.3, 2.4,
    2.5, 2.6,
    2.7, 2.8
  });

  EXPECT_EQ(weights, expected);
}
