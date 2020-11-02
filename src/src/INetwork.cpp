#include <INetwork.hpp>

namespace SimpleAI {

INetwork::INetwork(const Matrix& weights, const Activation& activation)
  : mActivation   (activation)
  , mWeightMatrix (weights)
{}

List INetwork::exec(const List& inputs) const
{
  List layer = inputs;
  for (const auto& weightLayer : mWeightMatrix)
  {
    layer = multiply(layer, weightLayer);
    for (auto& output : layer)
      output = mActivation(output);
  }
  return layer;
}

Matrix INetwork::getWeights() const
{
  return mWeightMatrix;
}

} // namespace SimpleAI
