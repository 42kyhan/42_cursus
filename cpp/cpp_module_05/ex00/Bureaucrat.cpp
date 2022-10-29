#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade is TOO HIGH");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaycrat grade is TOO LOW");
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : name_(name), grade_(grade)
{
	if (this->grade_ > 150)
		throw GradeTooLowException();
	if (this->grade_ < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

int	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

std::string	Bureaucrat::getName() const
{
	return (this->name_);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
	{
		*(const_cast<std::string*>(&this->name_)) = obj.getName();
		this->grade_ = obj.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	*this = obj;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade_ == 1)
		throw GradeTooHighException();
	this->grade_--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ == 150)
		throw GradeTooLowException();
	this->grade_++;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &obj)
{
	return (out << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}
