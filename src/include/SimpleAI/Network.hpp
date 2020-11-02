#ifndef SAI_NETWORK_HPP
#define SAI_NETWORK_HPP

#include <functional>
#include <vector>

//! \brief Пространство имен библиотеки SimpleAI
namespace SimpleAI {

using List       = std::vector<double>;
using Matrix     = std::vector<List>;
using Activation = std::function<double(const double& x)>;

//! \brief Класс для работы нейросети
class Network
{
public:
  /*!
   * \brief Конструктор с аргументами весов и функции активации
   * \details Создает нейросеть по готовой матрице весов
   * \param weights Весовыве коэффициенты
   * \param foo Функция активации
   */
  Network(const Matrix& weights, const Activation& foo);

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
   * \param weights Весовые коэффициенты
   * \return SimpleAI::List Список выходных значений слоя
   */
  List execLayer(const List& inputs, const List& weights) const;

  /*!
   * \brief Функция активации
   * \details Имеет вид double(const double& x), это может быть использовано
   * как лямбда функция вида [](const double& x) -> double {}
   */
  const Activation activation;

private:
  Matrix mWeightMatrix; //!< Матрица весовывх коэффициентов нейросети

};

} // namespace SimpleAI

#endif // SAI_NETWORK_HPP
