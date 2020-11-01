#include <gtest/gtest.h>

#include <NetworkTest.hpp>

using namespace SimpleAI::Tests;

TEST(DefaultCase, Test)
{
  NetworkTest network;
  auto layer = network.execLayer({}, {});
}
