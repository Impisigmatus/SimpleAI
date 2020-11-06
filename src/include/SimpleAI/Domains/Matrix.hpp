#ifndef SAI_MATRIX_HPP
#define SAI_MATRIX_HPP

#include <SimpleAI/Domains/List.hpp>

namespace SimpleAI {

class Matrix : public std::vector<List>
{
public:
  Matrix();
  Matrix(const std::initializer_list<List>& list);

  friend std::istream& operator>>(std::istream& stream, Matrix& matrix);
  friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

};

} // namespace SimpleAI

#endif // SAI_MATRIX_HPP
