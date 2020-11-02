#ifndef SAI_NETWORK_HPP
#define SAI_NETWORK_HPP

#include <SimpleAI/INetwork.hpp>

namespace SimpleAI {

//! \brief Реализация для работы нейросети на базе библиотеки OpenBLAS
class Network : public INetwork
{
public:
  Network(const Matrix& weights, const Activation& foo);

private:
  List multiply(const List& inputs, const List& weights) const override;

};

} // namespace SimpleAI

#endif // SAI_NETWORK_HPP
