#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): target(target), AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &another)
{
	if (this != &another)
		this->target = another.getTarget();
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &another): AForm(another.getName(), another.getGradeSign(), another.getGradeExecute())
{
	*this = another;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw (RobotomyRequestForm::FormIsNotSigned());
	else if (executor.getGrade() > this->getGradeExecute())
		throw (RobotomyRequestForm::GradeTooLowException());
	srand(time(0));
	if (rand() % 2)
		std::cout << this -> target + " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Robotization of " + this -> target  + " failed !" << std::endl;
}

const char *RobotomyRequestForm::FormIsNotSigned::what() const throw()
{
	return ("THIS FORM HAS NOT BEEN SIGNED YET!");
}
