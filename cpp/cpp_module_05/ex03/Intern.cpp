#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &obj)
{
	static_cast<void>(obj);
}

Intern& Intern::operator=(Intern const &obj)
{
	static_cast<void>(obj);
	return (*this);
}

Intern::~Intern()
{
}

const char *Intern::MatchNothing::what(void) const throw()
{
	return ("Match Nothing");
}

Form* Intern::makeForm(std::string const &type, std::string const &name)
{
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (forms[i] == type)
			{
				std::cout << "Intern created " << type << ": " << name << std::endl;
				switch (i)
				{
				case 0:
					return new ShrubberyCreationForm(name);
					break;
				case 1:
					return new RobotomyRequestForm(name);
					break;
				case 2:
					return new PresidentialPardonForm(name);
					break;
				}
			}
		}
		throw MatchNothing();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern cannot create " << type << ": " << name << " because " << e.what() << '\n';
		return NULL;
	}
	
}
