#ifndef SAI_UTILITIES_HPP
#define SAI_UTILITIES_HPP

#include <SimpleAI/Concepts.hpp>

#include <random>

namespace SimpleAI {

//! \brief TODO
class Utilities
{
public:
  static void fillRand(Matrix& matrix);

  static double rand(const double& begin = 0, const double& end = 1);
  static int    rand(const int&    begin,     const int&    end);

private:
  static std::random_device mRandom;
  static std::mt19937       mGenerator;

};

} // namespace SimpleAI

#endif // SAI_UTILITIES_HPP
