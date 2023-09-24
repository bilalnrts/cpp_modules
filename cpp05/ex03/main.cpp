#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	someRandomIntern;
	Bureaucrat b("brc", 1);
	AForm*	rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;
	return (0);
}
