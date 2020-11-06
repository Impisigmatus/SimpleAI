#ifndef SAI_UTILITIES_HPP
#define SAI_UTILITIES_HPP

#include <SimpleAI/Domains/Matrix.hpp>

#include <random>

namespace SimpleAI {

//! \brief Класс со стаическими методами помогающими в работе с нейросетью
class Utilities
{
public:
  /*!
   * \brief Записывает матрицу весов в файл
   * \param weights Весовые коэффициенты
   * \param path Путь до файла
   * \return Возвращает true в случае успеха, иначе false
   */
  static bool serialize(const Matrix& weights, const std::string& path);

  /*!
   * \brief Читает матрицу весов из файла
   * \details Если не удалось прочитать матрицу весов, то вернет пустую матрицу
   * \param path Путь до файла
   * \return SimpleAI::Matrix Прочитанная матрица весов
   */
  static Matrix deserialize(const std::string& path);

  /*!
   * \brief Заполняет случайными занчениями матрицу
   * \details Заполняет случайными значениями только те элементы, под которые выделена память
   * (изменяет существующие значения на случайные)
   * \param matrix Ссылка на матрицу, которой надо расставить случайные значениня
   */
  static void fillRand(Matrix& matrix);

  /*!
   * \brief Находит случайное значение в заданном диапазоне
   * \param begin Минимально возможное случайное число
   * \param end Максимально возможное случайное число
   * \return Случайное число из заданного диапазона
   */
  static double rand(const double& begin = 0, const double& end = 1);
  static int    rand(const int&    begin,     const int&    end);

private:
  static std::random_device mRandom;
  static std::mt19937       mGenerator;

};

} // namespace SimpleAI

#endif // SAI_UTILITIES_HPP
