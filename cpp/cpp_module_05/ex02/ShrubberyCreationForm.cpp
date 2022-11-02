#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	return ((*dynamic_cast<ShrubberyCreationForm*>(&Form::operator=(obj))));
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : Form(obj)
{
	setType("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(target, 145, 137)
{
	setType("ShrubberyCreationForm");
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	executable(executor);
	std::ofstream out(getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (out.fail())
		throw OpenFileFail();
	std::string shrubbery = "               ,@@@@@@@,\n"
                          "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                          "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                          "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                          "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                          "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                          "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                          "       |o|        | |         | |\n"
                          "       |.|        | |         | |\n"
                          "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
	out << shrubbery;
	out.close();
}
