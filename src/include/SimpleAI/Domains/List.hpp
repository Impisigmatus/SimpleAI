#ifndef SAI_LIST_HPP
#define SAI_LIST_HPP

#include <vector>

namespace SimpleAI {

//! \brief Список вещественных чисел
class List : public std::vector<double>
{
public:
  //! \brief Конструктор по-умолчанию создает пустой список
  List();

  /*!
   * \brief Конструктор с параметром размера списка
   * \details Создает список заданного размера инициализируя его значениями по-умолчанию
   * \param size Размер списка
   */
  List(const size_t& size);

  /*!
   * \brief Конструктор со списком инициализации
   * \details Создает список вещественных чисел по списку инициализации
   * \param list Список инициализации
   */
  List(const std::initializer_list<double>& list);

  /*!
   * \brief Оператор ввода
   * \param stream Поток из которого читать значения
   * \param list Список в который записывать значения
   * \return std::istream& Поток после ввода
   */
  friend std::istream& operator>>(std::istream& stream, List& list);

  /*!
   * \brief Оператор вывода
   * \param stream Поток в который записывать значения
   * \param list Список из которого читать значения
   * \return std::ostream& Поток после вывода
   */
  friend std::ostream& operator<<(std::ostream& stream, const List& list);

};

} // namespace SimpleAI

#endif // SAI_LIST_HPP
