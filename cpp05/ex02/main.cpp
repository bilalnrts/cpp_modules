#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	bilal("bilal", 1);
	AForm *a = new ShrubberyCreationForm("bilo");
	AForm *b = new RobotomyRequestForm("bilo1");
	AForm *c = new PresidentialPardonForm("bilo2");

	a->beSigned(bilal);
	a->execute(bilal);
	b->beSigned(bilal);
	b->execute(bilal);
	c->beSigned(bilal);
	c->execute(bilal);

	bilal.executeForm(*a);
	return (0);
}
