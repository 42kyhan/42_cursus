#ifndef PRESIDENTPARDONFORM
# define PRESIDENTPARDONFORM

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();
public:
	void	execute(Bureaucrat const &executor) const;

	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &obj);
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm& operator=(PresidentialPardonForm const &obj);
};

#endif
