#include <gtest/gtest.h>

#include <SimpleAI/Utilities.hpp>

#include <fstream>
#include <sstream>

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

  std::fstream fout;
  // Читаем сериализованные данные
  std::stringstream result;
  fout.open(PATH);
  if (!fout.is_open())
    FAIL();
  result << fout.rdbuf();
  fout.close();

  // Читаем ассет
  std::stringstream expected;
  fout.open(std::string(ASSETS_PATH) + PATH);
  if (!fout.is_open())
    FAIL();
  expected << fout.rdbuf();
  fout.close();

  // Сравниваем
  EXPECT_EQ(result.str(), expected.str());
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
