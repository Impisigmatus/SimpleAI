#ifndef SAI_EXAMPLE_TEACHER_HPP
#define SAI_EXAMPLE_TEACHER_HPP

#include <ITeacher.hpp>

class Teacher : public ITeacher
{
public:
  Teacher(const size_t& iterations, const size_t& population, const double& step);

private:
  Students getPopulation(const Matrix& weights) const override;
  void log(const Student& student) const override;

  double grading(const List& outputs, const size_t& answer) const;

private:
  Matrix              mInputs;
  std::vector<size_t> mAnswers;

};

#endif // SAI_EXAMPLE_TEACHER_HPP
