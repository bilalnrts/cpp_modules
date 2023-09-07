#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string	_target;
	public :
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		void		execute(Bureaucrat const & executor) const;
};

#endif


//                ,@@@@@@@,
//        ,,,.   ,@@@@@@/@@,  .oo8888o.
//     ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
//    ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
//    %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
//    %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
//    `&%\ ` /%&'    |.|        \ '|8'
//        |o|        | |         | |
//        |.|        | |         | |
//     \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_
