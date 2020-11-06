#ifndef SAI_CONCEPTS_HPP
#define SAI_CONCEPTS_HPP

#include <functional>
#include <vector>

namespace SimpleAI {

class List : public std::vector<double>
{
public:
  List();
  List(const size_t& size);
  List(const std::initializer_list<double>& list);

  friend std::ostream& operator<<(std::ostream& stream, const List& list);
  friend std::istream& operator>>(std::istream& stream, List& list);

};

using Matrix = std::vector<List>;
using Activation = std::function<double(const double& x)>;

} // namespace SimpleAI

#endif // SAI_CONCEPTS_HPP
