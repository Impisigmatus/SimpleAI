#ifndef SAI_CONCEPTS_HPP
#define SAI_CONCEPTS_HPP

#include <functional>
#include <vector>

namespace SimpleAI {

using List       = std::vector<double>;
using Matrix     = std::vector<List>;
using Activation = std::function<double(const double& x)>;

} // namespace SimpleAI

#endif // SAI_CONCEPTS_HPP
