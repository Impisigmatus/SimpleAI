#include <Domains/Matrix.hpp>

#include <istream>
#include <ostream>

namespace SimpleAI {

Matrix::Matrix()
  : std::vector<List> ()
{}

Matrix::Matrix(const std::initializer_list<List>& list)
  : std::vector<List> (list)
{}

std::istream& operator>>(std::istream& stream, Matrix& matrix)
{

}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix)
{

}

} // namespace SimpleAI
