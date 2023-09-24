#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{
}

Bureaucrat::Bureaucrat(int grade) : name("Default"), grade(grade)
{
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &another)
{
	*this = another;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &another)
{
	if (this != &another)
		this->grade = another.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

int	Bureaucrat::increment()
{
	--this->grade;
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	return (this->grade);
}

int	Bureaucrat::decrement()
{
	++this->grade;
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	return (this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GRADE TOO HIGH !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GRADE TOO LOW !");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << b.getName() + ", bureaucrat grade " << b.getGrade() << ".";
	return (o);
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}

}
