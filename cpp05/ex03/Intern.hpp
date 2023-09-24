#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public :
		Intern();
		Intern(const Intern &another);
		~Intern();
		Intern &operator=(const Intern &another);
		AForm *makeForm(std::string nameOfForm, std::string target);
};

#endif
