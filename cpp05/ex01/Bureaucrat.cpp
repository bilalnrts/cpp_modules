#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &another) : _name(another._name)
{
	this -> _grade = another._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &another)
{
	if (&another != this)
		this -> _grade = another._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string	Bureaucrat::getName(void) const
{
	return (this -> _name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this -> _grade);
}

void	Bureaucrat::increment()
{
	--this -> _grade;
	if (this -> _grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrement()
{
	++this -> _grade;
	if (this -> _grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this -> _name << " signed " + f.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this -> _name << " couldn't sign " << f.getName() + " because " + this -> _name + "'s grade is too low." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << b.getName() + ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (o);
}
