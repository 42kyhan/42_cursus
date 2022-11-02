#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include "fstream"

class Form
{
private:
	std::string const	type_;
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
	std::string const &getType() const;
	void	setType(std::string const &type);
	void	executable(Bureaucrat const &obj) const;

	Form(std::string const &name, int const &signGrade, int const &execGrade);
	virtual ~Form(); 
 	Form& operator=(Form const &obj);
	Form(Form const &obj);
	void	beSigned(Bureaucrat const &obj);
	virtual void	execute(Bureaucrat const &executor) const = 0;

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

	class FormIsNotSigned : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class OpenFileFail : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &obj);

#endif
