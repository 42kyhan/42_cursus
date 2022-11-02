#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
private:
	std::string	const	name_;
	int const signGrade_;
	int const execGrade_;
	bool signed_;
	Form();
public:
	std::string	const &getName() const;
	int const &getSignGrade() const;
	int const &getExecGrade() const;
	bool const &getSigned() const;

	Form(std::string const &name, int const &signGrade, int const &execGrade);
	~Form();
 	Form& operator=(Form const &obj);
	Form(Form const &obj);
	void	beSigned(Bureaucrat const &obj);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &obj);

#endif
