#ifndef SAI_MATRIX_HPP
#define SAI_MATRIX_HPP

#include <SimpleAI/Domains/List.hpp>

namespace SimpleAI {

//! \brief Класс матрицы
class Matrix : public std::vector<List>
{
public:
  //! \brief Конструктор по-умолчанию создает пустую матрицу
  Matrix();

  /*!
   * \brief Конструктор со списком инициализации
   * \details Создает матрицу по списку инициализации
   * \param list Список инициализации
   */
  Matrix(const std::initializer_list<List>& list);

  /*!
   * \brief Оператор ввода
   * \param stream Поток из которого читать значения
   * \param matrix Матрица в которую записывать значения
   * \return std::istream& Поток после ввода
   */
  friend std::istream& operator>>(std::istream& stream, Matrix& matrix);

  /*!
   * \brief Оператор вывода
   * \param stream Поток в который записывать значения
   * \param matrix Матрица из которой читать значения
   * \return std::ostream& Поток после вывода
   */
  friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

};

} // namespace SimpleAI

#endif // SAI_MATRIX_HPP
