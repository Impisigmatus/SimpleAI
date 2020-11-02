#include <Network.hpp>

#include <cblas.h>

namespace SimpleAI {

Network::Network(const Matrix& weights, const Activation& foo)
  : activation (foo)
  , mWeights   (weights)
{}

List Network::exec(const List& inputs) const
{
  List layer = inputs;
  for (const auto& weights : mWeights)
    layer = normalize(execLayer(layer, weights));
  return layer;
}

List Network::execLayer(const List& inputs, const List& weights) const
{
  List outputs(static_cast<size_t>(weights.size() / inputs.size()));

  cblas_dgemm(
    CblasColMajor, CblasNoTrans, CblasNoTrans,
    static_cast<int>(outputs.size()), 1, static_cast<int>(inputs.size()),
    1,
    weights.data(), static_cast<int>(outputs.size()),
    inputs.data(),  static_cast<int>(inputs.size()),
    0,
    outputs.data(), static_cast<int>(outputs.size())
  );

  return outputs;
}

List Network::normalize(const List& layer) const
{
  List outputs;
  for (const auto& output : layer)
    outputs.push_back(activation(output));
  return outputs;
}

} // namespace SimpleAI
