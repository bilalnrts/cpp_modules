#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this -> getIsSigned())
		throw RobotomyRequestForm::FormNotSignedException();
	if (executor.getGrade() > this ->getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	srand(time(0));
	if (rand() % 2)
		std::cout << this -> _target + " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Robotization of " + this -> _target  + " failed !" << std::endl;
}
