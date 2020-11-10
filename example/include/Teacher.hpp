#ifndef SAI_EXAMPLE_TEACHER_HPP
#define SAI_EXAMPLE_TEACHER_HPP

#include <AbstractTeacher.hpp>

class Teacher : public AbstractTeacher
{
public:
  Teacher(const Matrix&              inputs,
          const std::vector<size_t>& answers,
          const size_t&              iterations,
          const size_t&              population,
          const double&              step);

private:
  std::shared_ptr<AbstractNetwork> makeNetwork(const Matrix& weights, const double& step) const override;
  double grading(const std::shared_ptr<AbstractNetwork>& network) const override;

  Matrix mutate (Matrix matrix, const double& step) const;

private:
  Matrix              mInputs;
  std::vector<size_t> mAnswers;

};

#endif // SAI_EXAMPLE_TEACHER_HPP
