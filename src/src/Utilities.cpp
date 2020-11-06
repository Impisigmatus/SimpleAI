#include <SimpleAI/Utilities.hpp>

#include <algorithm>
#include <fstream>

namespace SimpleAI {

std::random_device Utilities::mRandom;
std::mt19937 Utilities::mGenerator = std::mt19937(mRandom());

bool Utilities::serialize(const Matrix& weights, const std::string& path)
{
  std::ofstream fout(path);
  if (!fout.is_open())
    return false;

  fout << weights;
  fout.close();
  return true;
}

Matrix Utilities::deserialize(const std::string& path)
{
  std::ifstream fin(path);
  if (!fin.is_open())
    return Matrix();

  Matrix weights;
  fin >> weights;
  fin.close();
  return weights;
}

void Utilities::fillRand(Matrix& matrix)
{
  for (auto& list : matrix)
    std::generate(list.begin(), list.end(), []() { return rand(); });
}

double Utilities::rand(const double& begin, const double& end)
{
  std::uniform_real_distribution<double> distribution(begin, end);
  return distribution(mGenerator);
}

int Utilities::rand(const int& begin, const int& end)
{
  std::uniform_int_distribution<int> distribution(begin, end);
  return distribution(mGenerator);
}

} // namespace SimpleAI
