#include <Network.hpp>

#include <cblas.h>

namespace SimpleAI {

Network::Network(const Matrix& weights, const Activation& activation)
  : AbstractNetwork(weights, activation)
{}

List Network::multiply(const List& inputs, const List& weights) const
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
