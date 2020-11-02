#ifndef SAI_TESTS_NETWORK_F_HPP
#define SAI_TESTS_NETWORK_F_HPP

#include <SimpleAI/INetwork.hpp>

#include <gtest/gtest.h>

class NetworkF : public ::testing::Test
{
public:
  void SetUp() final override;

protected:
  bool listsEquals(const SimpleAI::List& first, const SimpleAI::List& second);

protected:
  SimpleAI::Matrix weights;

};

#endif // SAI_TESTS_NETWORK_F_HPP
