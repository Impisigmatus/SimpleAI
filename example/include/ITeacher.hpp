#ifndef SAI_EXAMPLE_ITEACHER_HPP
#define SAI_EXAMPLE_ITEACHER_HPP

#include <SimpleAI/INetwork.hpp>

using namespace SimpleAI;

struct Student
{
  std::shared_ptr<INetwork> network;
  double grade = 0;
};

using Students = std::vector<Student>;

class ITeacher
{
public:
  ITeacher(const size_t& iterations, const size_t& population, const double& step);
  virtual ~ITeacher() = default;

  std::shared_ptr<INetwork> teach(Matrix weights) const;

private:
  virtual Students getPopulation(const Matrix& weights) const = 0;
  virtual double grading(const std::shared_ptr<INetwork>& network) const = 0;
  virtual void log(const Student& student) const = 0;

protected:
  const size_t M_ITERATIONS;
  const size_t M_POPULATION;
  const double M_STEP;

  Activation mActivation;

};

#endif // SAI_EXAMPLE_ITEACHER_HPP
