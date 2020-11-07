#ifndef SAI_EXAMPLE_TEACHER_HPP
#define SAI_EXAMPLE_TEACHER_HPP

#include <ITeacher.hpp>

class Teacher : public ITeacher
{
public:
  Teacher(const size_t& iterations, const size_t& population, const double& step);

private:
  Students getPopulation(const Matrix& weights, const double& step) const override;
  double grading(const std::shared_ptr<INetwork>& network) const override;
  void log(const Student& student) const override;

  double grading(const List& outputs, const size_t& answer) const;
  Matrix mutate (Matrix matrix, const double& step) const;

private:
  Matrix              mInputs;
  std::vector<size_t> mAnswers;

};

#endif // SAI_EXAMPLE_TEACHER_HPP
