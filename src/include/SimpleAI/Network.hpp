#ifndef SAI_NETWORK_HPP
#define SAI_NETWORK_HPP

#include <vector>

//! \brief Пространство имен библиотеки SimpleAI
namespace SimpleAI {

using List = std::vector<double>;

//! \brief Класс для работы нейросети
class Network
{
public:
  //! Конструктор по-умолчанию
  Network() = default;

  /*!
   * \brief Производит вычисление весов выходного слоя
   * \param inputs Входные значения
   * \return SimpleAI::List Список значений выходного слоя
   */
  List exec(const List& inputs) const;

private:
  /*!
   * \brief Метод для расчета слоя
   * \param inputs Список выходных значенинй предыдущего слоя
   * \param weights Весовыве коэффициенты
   * \return SimpleAI::List Список выходных значений слоя
   */
  List execLayer(const List& inputs, const List& weights) const;

};

} // namespace SimpleAI

#endif // SIMPLEAI_NETWORK_HPP
