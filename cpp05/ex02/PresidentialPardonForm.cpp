#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this -> getIsSigned())
		throw PresidentialPardonForm::FormNotSignedException();
	if (executor.getGrade() > this ->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << this -> _target + " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}







