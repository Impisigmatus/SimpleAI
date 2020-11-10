#include <gtest/gtest.h>

#include <SimpleAI/Utilities.hpp>

#include <fstream>

TEST(SerializationCase, Serialize)
{
  const std::string PATH = "Serialize_test";

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

  EXPECT_TRUE(SimpleAI::Utilities::serialize(weights, PATH));

  std::fstream fout(PATH);
  if (!fout.is_open())
    FAIL();

  // Прочитать и сравнить
  fout.close();
}

TEST(SerializationCase, Deserialize)
{
  const std::string PATH = std::string(ASSETS_PATH) + "Deserialize_test";

  SimpleAI::Matrix weights = SimpleAI::Utilities::deserialize(PATH);
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
