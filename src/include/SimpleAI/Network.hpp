#ifndef SAI_NETWORK_HPP
#define SAI_NETWORK_HPP

#include <SimpleAI/AbstractNetwork.hpp>

namespace SimpleAI {

//! \brief Реализация для работы нейросети на базе библиотеки OpenBLAS
class Network : public AbstractNetwork
{
public:
  Network(const Matrix& weights, const Activation& activation);

private:
  List multiply(const List& inputs, const List& weights) const override;

};

} // namespace SimpleAI

#endif // SAI_NETWORK_HPP
