#ifndef SAI_INETWORK_HPP
#define SAI_INETWORK_HPP

#include <SimpleAI/Domains/Matrix.hpp>

//! \brief Пространство имен библиотеки SimpleAI
namespace SimpleAI {

using Activation = std::function<double(const double& x)>;

//! \brief Интерфейс для работы нейросети
class INetwork
{
public:
  /*!
   * \brief Конструктор с аргументами весов и функции активации
   * \details Создает нейросеть по готовой матрице весов
   * \param weights Весовыве коэффициенты
   * \param foo Функция активации
   */
  INetwork(const Matrix& weights, const Activation& activation);

  //! \brief Деструктор по-умолчанию
  virtual ~INetwork() = default;

  /*!
   * \brief Производит вычисление весов выходного слоя
   * \param inputs Входные значения
   * \return SimpleAI::List Список значений выходного слоя
   */
  List exec(const List& inputs) const;

  /*!
   * \brief Возвращает матрицу весовых коэффициентов
   * \return SimpleAI::Matrix Матрица весовых коэффициентов
   */
  Matrix getWeights() const;

private:
  /*!
   * \brief Метод для перемножения выходных значенинй предыдущего слоя на весовые коэффициенты
   * \param inputs Список выходных значенинй предыдущего слоя
   * \param weights Весовые коэффициенты
   * \return SimpleAI::List Список выходных значений слоя
   */
  virtual List multiply(const List& inputs, const List& weights) const = 0;

  /*!
   * \brief Функция активации
   * \details Имеет вид double(const double& x), это может быть использовано
   * как лямбда функция вида [](const double& x) -> double {}
   */
  const Activation mActivation;

private:
  Matrix mWeightMatrix; //!< Матрица весовывх коэффициентов нейросети

};

} // namespace SimpleAI

#endif // SAI_INETWORK_HPP
