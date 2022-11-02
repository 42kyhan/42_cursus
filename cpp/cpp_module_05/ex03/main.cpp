#include "Intern.hpp"

void	main_main()
{
	Intern kyhan;

	Form *a = kyhan.makeForm("ShrubberyCreationForm", "sr");
	Form *b = kyhan.makeForm("RobotomyRequestForm", "robo");
	Form *c = kyhan.makeForm("PresidentialPardonForm", "ppp");

	std::cout << *a << std::endl << *b << std::endl << *c << std::endl;

	Form *d = kyhan.makeForm("zdffhdfh", "asd");
	static_cast<void>(d);
	delete a;
	delete b;
	delete c;
}

int	main()
{
	main_main();
	system("leaks ex03");
}
