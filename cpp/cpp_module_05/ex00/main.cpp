#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	kyhan("kyhan", 1);
	Bureaucrat	anony("ano", 150);

	std::cout << kyhan << std::endl;
	// kyhan.incrementGrade();
	// std::cout << kyhan << std::endl;
	kyhan.decrementGrade();
	// std::cout << kyhan << std::endl;
	// kyhan.decrementGrade();
	std::cout << kyhan << std::endl;

	std::cout << anony << std::endl;
	anony.incrementGrade();
	std::cout << anony << std::endl;
}
