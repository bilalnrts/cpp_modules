#include "AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExecute): name(name), gradeSign(gradeSign), gradeExecute(gradeExecute), isSigned(false)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw(AForm::GradeTooLowException());
	else if (gradeSign < 1 || gradeExecute < 1)
		throw(AForm::GradeTooHighException());
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &another): name(another.getName()), gradeSign(another.getGradeSign()), gradeExecute(another.getGradeExecute())
{
	*this = another;
}

AForm &AForm::operator=(const AForm &another)
{
	if (this != &another)
		this->isSigned = another.getIsSigned();
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int	AForm::getGradeSign() const
{
	return (this -> gradeSign);
}

int	AForm::getGradeExecute() const
{
	return (this->gradeExecute);
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("GRADE TOO LOW !");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("GRADE TOO HIGH !");
}

std::ostream &operator<<(std::ostream &o, AForm &f)
{
	o << "Name : " + f.getName() << std::endl;
	o << "Is signed : " << f.getIsSigned() << std::endl;
	o << "Form grade to sign " << f.getGradeSign() << std::endl;
	o << "Form grade to execute " << f.getGradeExecute() << std::endl;
	return (o);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->gradeSign)
		this->isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}
