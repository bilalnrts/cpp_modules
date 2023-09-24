#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): target(target), AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &another)
{
	if (this != &another)
		this->target = another.getTarget();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &another): AForm(another.getName(), another.getGradeSign(), another.getGradeExecute())
{
	*this = another;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw (PresidentialPardonForm::FormIsNotSigned());
	else if (executor.getGrade() > this->getGradeExecute())
		throw (PresidentialPardonForm::GradeTooLowException());
	std::cout << this -> target + " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}

const char *PresidentialPardonForm::FormIsNotSigned::what() const throw()
{
	return ("THIS FORM HAS NOT BEEN SIGNED YET!");
}
