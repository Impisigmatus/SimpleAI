#include <SimpleAI/Utilities.hpp>

namespace SimpleAI {

std::random_device Utilities::mRandom;
std::mt19937 Utilities::mGenerator = std::mt19937(mRandom());

double Utilities::rand(const double& begin, const double& end)
{
  std::uniform_real_distribution<double> uid(begin, end);
  return uid(mGenerator);
}

int Utilities::rand(const int& begin, const int& end)
{
  std::uniform_int_distribution<int> uid(begin, end);
  return uid(mGenerator);
}

} // namespace SimpleAI
