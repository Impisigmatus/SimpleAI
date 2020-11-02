#ifndef SAI_TEACHER_HPP
#define SAI_TEACHER_HPP

#include <SimpleAI/INetwork.hpp>

namespace SimpleAI {

struct Student
{
  std::shared_ptr<INetwork> network;
  double grade = 0;
};

using Students = std::vector<Student>;

class Teacher
{
public:
  Teacher(const size_t& iterations, const size_t& population, const double& step);

  std::shared_ptr<INetwork> teach(Matrix weights) const;

private:
  Students getPopulation(const Matrix& weights) const;

  double grading(const List& outputs, const size_t& answer) const;

  void log(const Student& student) const;

private:
  Matrix              mInputs;
  std::vector<size_t> mAnswers;

private:
  const size_t M_ITERATIONS;
  const size_t M_POPULATION;
  const double M_STEP;

  Activation mActivation;

};

} // namespace SimpleAI

#endif // SAI_TEACHER_HPP
