#ifndef SAI_LIST_HPP
#define SAI_LIST_HPP

#include <vector>

namespace SimpleAI {

class List : public std::vector<double>
{
public:
  List();
  List(const size_t& size);
  List(const std::initializer_list<double>& list);

  friend std::istream& operator>>(std::istream& stream, List& list);
  friend std::ostream& operator<<(std::ostream& stream, const List& list);

};

} // namespace SimpleAI

#endif // SAI_LIST_HPP
