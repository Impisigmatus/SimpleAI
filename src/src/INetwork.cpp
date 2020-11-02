#include <INetwork.hpp>

namespace SimpleAI {

INetwork::INetwork(const Matrix& weights, const Activation& foo)
  : activation    (foo)
  , mWeightMatrix (weights)
{}

List INetwork::exec(const List& inputs) const
{
  List layer = inputs;
  for (const auto& weightLayer : mWeightMatrix)
  {
    layer = execLayer(layer, weightLayer);
    for (auto& output : layer)
      output = activation(output);
  }
  return layer;
}

} // namespace SimpleAI
