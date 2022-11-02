#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();
public:
	void	execute(Bureaucrat const &executor) const;

	ShrubberyCreationForm(ShrubberyCreationForm const &obj);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &obj);
	ShrubberyCreationForm(std::string const &target);
	~ShrubberyCreationForm();
};

#endif
