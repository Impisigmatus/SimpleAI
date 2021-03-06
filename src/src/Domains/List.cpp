#include <Domains/List.hpp>

#include <istream>
#include <ostream>

namespace SimpleAI {

List::List()
  : std::vector<double> ()
{}

List::List(const size_t& size)
  : std::vector<double> (size)
{}

List::List(const std::initializer_list<double>& list)
  : std::vector<double> (list)
{}

std::istream& operator>>(std::istream& stream, List& list)
{
  double buffer;
  while (stream >> buffer)
    list.push_back(buffer);
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const List& list)
{
  for (size_t i = 0; i < list.size(); i++)
    stream << list[i] << (i == list.size()-1 ? '\n' : ' ');
  return stream;
}

} // namespace SimpleAI
