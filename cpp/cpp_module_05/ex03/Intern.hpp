#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	class MatchNothing : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	Form* makeForm(std::string const &type, std::string const &name);

	Intern();
	~Intern();
	Intern(Intern const &obj);
	Intern& operator=(Intern const &obj);
};

#endif
