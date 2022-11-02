#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	return ((*dynamic_cast<PresidentialPardonForm*>(&Form::operator=(obj))));
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : Form(obj)
{
	setType("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form(target, 25, 5)
{
	setType("PresidentialPardonForm");
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	executable(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
