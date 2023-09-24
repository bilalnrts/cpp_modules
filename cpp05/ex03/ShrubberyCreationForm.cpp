#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): target(target), AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &another)
{
	if (this != &another)
		this->target = another.getTarget();
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &another): AForm(another.getName(), another.getGradeSign(), another.getGradeExecute())
{
	*this = another;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw (ShrubberyCreationForm::FormIsNotSigned());
	else if (executor.getGrade() > this->getGradeExecute())
		throw (ShrubberyCreationForm::GradeTooLowException());
	std::ofstream	outfile(this -> target + "_shrubbery");
	outfile << "                ,@@@@@@@," << std::endl;
	outfile << "        ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outfile << "     ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outfile << "    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outfile << "    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outfile << "    %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outfile << "    `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outfile << "        |o|        | |         | |" << std::endl;
	outfile << "        |.|        | |         | |" << std::endl;
	outfile << "     \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	outfile.close();
}

const char *ShrubberyCreationForm::FormIsNotSigned::what() const throw()
{
	return ("THIS FORM HAS NOT BEEN SIGNED YET!");
}
