#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (this -> _gradeToSign > 150 || this -> _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (this -> _gradeToSign < 1 || this -> _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const &another) : _name(another.getName()), _gradeToSign(another.getGradeToSign()), _gradeToExecute(another.getGradeToExecute())
{
	this -> _isSigned = another.getIsSigned();
}

AForm &AForm::operator=(AForm const &another)
{
	if (this != &another)
		this -> _isSigned = another.getIsSigned();
	return (*this);
}

AForm::~AForm()
{
}

const std::string	AForm::getName(void) const
{
	return (this -> _name);
}

int const			AForm::getGradeToSign(void) const
{
	return (this -> _gradeToSign);
}

int const			AForm::getGradeToExecute(void) const
{
	return (this -> _gradeToExecute);
}
bool				AForm::getIsSigned(void) const
{
	return (this -> _isSigned);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("The form must be signed !");
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= this -> _gradeToSign)
		this -> _isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm &f)
{
	o << "Form name : " + f.getName() << " | Form is signed : " << f.getIsSigned() << " | Form grade to sign : " << f.getGradeToSign() << " | Form grade to execute : " << f.getGradeToExecute();
	return (o);
}
