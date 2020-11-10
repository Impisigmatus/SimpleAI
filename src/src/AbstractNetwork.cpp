#include <AbstractNetwork.hpp>

namespace SimpleAI {

AbstractNetwork::AbstractNetwork(const Matrix& weights, const Activation& activation)
  : mActivation   (activation)
  , mWeightMatrix (weights)
{}

List AbstractNetwork::exec(const List& inputs) const
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

Matrix AbstractNetwork::getWeights() const
{
  return mWeightMatrix;
}

} // namespace SimpleAI
