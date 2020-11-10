#ifndef SAI_EXAMPLE_ITEACHER_HPP
#define SAI_EXAMPLE_ITEACHER_HPP

#include <SimpleAI/AbstractNetwork.hpp>

using namespace SimpleAI;

struct Student
{
  std::shared_ptr<AbstractNetwork> network;
  double grade = 0;
};

using Students = std::vector<Student>;

class ITeacher
{
public:
  ITeacher(const size_t& iterations, const size_t& population, const double& step);
  virtual ~ITeacher() = default;

  std::shared_ptr<AbstractNetwork> teach(Matrix weights) const;

private:
  Student getBest(const Students& students) const;

  virtual Students getPopulation(const Matrix& weights, const double& step) const = 0;
  virtual double grading(const std::shared_ptr<AbstractNetwork>& network) const = 0;
  virtual void log(const Student& student, const size_t& i) const = 0;

protected:
  const size_t M_ITERATIONS;
  const size_t M_POPULATION;
  const double M_STEP;

  Activation mActivation;

};

#endif // SAI_EXAMPLE_ITEACHER_HPP
