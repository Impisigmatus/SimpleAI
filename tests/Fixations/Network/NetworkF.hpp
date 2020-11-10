#ifndef SAI_TESTS_NETWORK_F_HPP
#define SAI_TESTS_NETWORK_F_HPP

#include <SimpleAI/AbstractNetwork.hpp>

#include <gtest/gtest.h>

class NetworkF : public ::testing::Test
{
public:
  void SetUp() final override;

protected:
  bool listsEquals(const SimpleAI::List& first, const SimpleAI::List& second);

protected:
  SimpleAI::Matrix weights;

private:
  const double M_ACCURACY = 0.0000001;

};

#endif // SAI_TESTS_NETWORK_F_HPP
