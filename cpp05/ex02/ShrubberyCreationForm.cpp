#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this -> getIsSigned())
		throw ShrubberyCreationForm::FormNotSignedException();
	if (executor.getGrade() > this ->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream	outfile(this -> _target + "_shrubbery");
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
