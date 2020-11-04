#include <SimpleAI/Utilities.hpp>

#include <algorithm>
#include <fstream>
#include <sstream>

namespace SimpleAI {

std::random_device Utilities::mRandom;
std::mt19937 Utilities::mGenerator = std::mt19937(mRandom());

bool Utilities::serialize(const Matrix& weights, const std::string& path)
{
  std::ofstream fout(path, std::ios::binary);
  if (!fout.is_open())
    return false;

  for (const auto& layer : weights)
  {
    for (const auto& weight : layer)
      fout << weight << ' ';
    fout << std::endl;
  }

  fout.close();
  return true;
}

Matrix Utilities::deserialize(const std::string& path)
{
  std::ifstream fin;
  fin.open(path);
  if (!fin.is_open())
    return Matrix();

  Matrix weights;

  std::string buff;
  while (std::getline(fin, buff))
  {
    List layer;

    if (buff.back() == ' ')
      buff.pop_back();
    std::stringstream stream(buff);
    while (!stream.eof())
    {
      double weight;
      stream >> weight;
      layer.push_back(weight);
    }
    weights.push_back(layer);
  }

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
    for (auto& weight : list)
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
  return matrix;
}

void Utilities::fillRand(Matrix& matrix)
{
  for (auto& list : matrix)
    std::generate(list.begin(), list.end(), []() { return rand(); });
}

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
