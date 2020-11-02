#ifndef SAI_TESTS_NETWORK_F_HPP
#define SAI_TESTS_NETWORK_F_HPP

#include <SimpleAI/INetwork.hpp>

#include <gtest/gtest.h>

class NetworkF : public ::testing::Test
{
public:
  void SetUp() final override;

protected:
  bool doubleEQ(const double& a, const double& b, const double& delta = 0.000001);

protected:
  SimpleAI::Matrix weights;

};

#endif // SAI_TESTS_NETWORK_F_HPP
