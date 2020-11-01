#ifndef SAI_NETWORK_HPP
#define SAI_NETWORK_HPP

#include <vector>

//! \brief Пространство имен библиотеки SimpleAI
namespace SimpleAI {

//! \brief Класс для работы нейросети
class Network
{
public:
  //! Конструктор по-умолчанию
  Network() = default;

private:
  /*!
   * \brief Метод для расчета слоя
   * \param inputs Список выходных значенинй предыдущего слоя
   * \param weights Весовыве коэффициенты
   * \return std::vector<double> Список выходных значений слоя
   */
  std::vector<double> execLayer(const std::vector<double>& inputs,
                                const std::vector<double>& weights);

};

} // namespace SimpleAI

#endif // SIMPLEAI_NETWORK_HPP
