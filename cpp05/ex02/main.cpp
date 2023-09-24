#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// ******** CASE 1 ********
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
	bilal.executeForm(*b);
	bilal.executeForm(*c);

	// ******** CASE 2 ********
	// Bureaucrat	bilal("bilal", 130);
	// AForm *a = new ShrubberyCreationForm("bilo");
	// AForm *b = new RobotomyRequestForm("bilo1");
	// AForm *c = new PresidentialPardonForm("bilo2");
	// try
	// {
	// 	a->beSigned(bilal);
	// 	a->execute(bilal);
	// 	b->beSigned(bilal);
	// 	b->execute(bilal);
	// 	c->beSigned(bilal);
	// 	c->execute(bilal);

	// 	bilal.executeForm(*a);
	// 	bilal.executeForm(*b);
	// 	bilal.executeForm(*c);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	return (0);
}
