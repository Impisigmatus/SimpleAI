#include <gtest/gtest.h>

#include <SimpleAI/Utilities.hpp>

TEST(RandomCase, RealDefault)
{
  double a = SimpleAI::Utilities::rand();
  double b = SimpleAI::Utilities::rand();

  ASSERT_NE(a, b);

  EXPECT_GE(a, 0);
  EXPECT_LE(a, 1);
  EXPECT_GE(b, 0);
  EXPECT_LE(b, 1);
}

TEST(RandomCase, RealPositive)
{
  const double begin = 5;
  const double end   = 10;

  double a = SimpleAI::Utilities::rand(begin, end);
  double b = SimpleAI::Utilities::rand(begin, end);

  ASSERT_NE(a, b);

  EXPECT_GE(a, begin);
  EXPECT_LE(a, end);
  EXPECT_GE(b, begin);
  EXPECT_LE(b, end);
}

TEST(RandomCase, RealNegative)
{
  const double begin = -10;
  const double end   = -5;

  double a = SimpleAI::Utilities::rand(begin, end);
  double b = SimpleAI::Utilities::rand(begin, end);

  ASSERT_NE(a, b);

  EXPECT_GE(a, begin);
  EXPECT_LE(a, end);
  EXPECT_GE(b, begin);
  EXPECT_LE(b, end);
}

TEST(RandomCase, IntPositive)
{
  const int begin = 0;
  const int end   = 50;

  int a = SimpleAI::Utilities::rand(begin, end);
  int b = SimpleAI::Utilities::rand(begin, end);

  ASSERT_NE(a, b);

  EXPECT_GE(a, begin);
  EXPECT_LE(a, end);
  EXPECT_GE(b, begin);
  EXPECT_LE(b, end);
}

TEST(RandomCase, IntNegative)
{
  const int begin = -50;
  const int end   = 0;

  int a = SimpleAI::Utilities::rand(begin, end);
  int b = SimpleAI::Utilities::rand(begin, end);

  ASSERT_NE(a, b);

  EXPECT_GE(a, begin);
  EXPECT_LE(a, end);
  EXPECT_GE(b, begin);
  EXPECT_LE(b, end);
}
