#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	kyhan("kyhan", 2);
	Bureaucrat	anony("ano", 30);
	ShrubberyCreationForm a("shru");
	RobotomyRequestForm b("robot");
	PresidentialPardonForm c("pardon");
	std::cout << a << std::endl << b << std::endl << c << std::endl;

	kyhan.signForm(a);
	anony.signForm(b);
	kyhan.signForm(c);

	kyhan.executeForm(a);
	kyhan.executeForm(b);
	kyhan.executeForm(c);

	anony.executeForm(c);
	anony.executeForm(a);
}
