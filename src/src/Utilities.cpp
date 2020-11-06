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

Matrix Utilities::mutate(Matrix matrix, const double& step)
{
  const auto shift = [](double& weight, const double& step) {
    weight += step;
    if (weight > 1)
      weight = 1;
    if (weight < 0)
      weight = 0;
  };

  for (auto& list : matrix)
  {
    for (auto& weight : list)
    {
      switch (rand(1, 3))
      {
        case 1:
          shift(weight, step);
          break;
        case 2:
          shift(weight, -step);
          break;
        default:
          break;
      }
    }
  }

  return matrix;
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
