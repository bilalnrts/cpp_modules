#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (this -> _gradeToSign > 150 || this -> _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (this -> _gradeToSign < 1 || this -> _gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &another) : _name(another.getName()), _gradeToSign(another.getGradeToSign()), _gradeToExecute(another.getGradeToExecute())
{
	this -> _isSigned = another.getIsSigned();
}

Form &Form::operator=(Form const &another)
{
	if (this != &another)
		this -> _isSigned = another.getIsSigned();
	return (*this);
}

Form::~Form()
{
}

const std::string	Form::getName(void) const
{
	return (this -> _name);
}

int const			Form::getGradeToSign(void) const
{
	return (this -> _gradeToSign);
}

int const			Form::getGradeToExecute(void) const
{
	return (this -> _gradeToExecute);
}
bool				Form::getIsSigned(void) const
{
	return (this -> _isSigned);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= this -> _gradeToSign)
		this -> _isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Form &f)
{
	o << "Form name : " + f.getName() << " | Form is signed : " << f.getIsSigned() << " | Form grade to sign : " << f.getGradeToSign() << " | Form grade to execute : " << f.getGradeToExecute();
	return (o);
}
