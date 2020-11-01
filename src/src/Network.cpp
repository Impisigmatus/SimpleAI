#include <Network.hpp>

#include <cblas.h>

namespace SimpleAI {

List Network::exec(const List& /*inputs*/) const
{
  return List();
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

} // namespace SimpleAI
