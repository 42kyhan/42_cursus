#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	kyhan("kyhan", 30);
	Bureaucrat	anony("ano", 50);
	Form	a("a", 40, 40);
	Form	b("b", 20, 20);

	kyhan.signForm(a);
	anony.signForm(a);
	kyhan.signForm(b);
	anony.signForm(b);
	std::cout << a << std::endl << b << std::endl;
}
