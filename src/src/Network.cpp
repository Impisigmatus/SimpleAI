#include <Network.hpp>

#include <cblas.h>

namespace SimpleAI {

Network::Network(const Matrix& weights, const Activation& foo)
  : activation    (foo)
  , mWeightMatrix (weights)
{}

List Network::exec(const List& inputs) const
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

List Network::execLayer(const List& inputs, const List& weights) const
{
  const int inputSize  = static_cast<int>(inputs.size());
  const int outputSize = static_cast<int>(weights.size()) / inputSize;

  List outputs(static_cast<size_t>(outputSize));

  cblas_dgemm(
    CblasColMajor, CblasNoTrans, CblasNoTrans,
    outputSize, 1,  inputSize,
    1,
    weights.data(), outputSize,
    inputs.data(),  inputSize,
    0,
    outputs.data(), outputSize
  );

  return outputs;
}

} // namespace SimpleAI
