#ifndef SAI_TEST_NETWORK_HPP
#define SAI_TEST_NETWORK_HPP

#include <AI/Network.hpp>

namespace SimpleAI::Tests {

class NetworkTest : public SimpleAI::Network
{
public:
  std::vector<double> execLayer(const std::vector<double>& inputs,
                                const std::vector<double>& weights)
  {
    return Network::execLayer(inputs, weights);
  }

};

} // namespace SimpleAI::Tests

#endif // SAI_TEST_NETWORK_HPP
