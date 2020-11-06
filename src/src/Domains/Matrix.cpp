#include <Domains/Matrix.hpp>

#include <sstream>

namespace SimpleAI {

Matrix::Matrix()
  : std::vector<List> ()
{}

Matrix::Matrix(const std::initializer_list<List>& list)
  : std::vector<List> (list)
{}

std::istream& operator>>(std::istream& stream, Matrix& matrix)
{
  std::string line;
  while (std::getline(stream, line))
  {
    std::stringstream buffer(line);
    List list;
    buffer >> list;
    matrix.push_back(list);
  }
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix)
{
  for (const auto& list : matrix)
    stream << list;
  return stream;
}

} // namespace SimpleAI
