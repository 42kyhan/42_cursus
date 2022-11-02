#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
private:
	std::string const	name_;
	int					grade_;
	Bureaucrat();
public:

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	~Bureaucrat();
	Bureaucrat(Bureaucrat const &obj);
	Bureaucrat(std::string const &name, int const &grade);
	Bureaucrat& operator=(Bureaucrat const &obj);

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(Form &obj) const;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const &obj);

#endif
