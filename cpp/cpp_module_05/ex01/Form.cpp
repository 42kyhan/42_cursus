#include "Form.hpp"

Form::Form(std::string const &name, int const &signGrade, int const &execGrade)
	: name_(name), signGrade_(signGrade), execGrade_(execGrade), signed_(false)
{
	if (signGrade_ < 1 || execGrade_ < 1)
		throw GradeTooHighException();
	if (signGrade_ > 150 || execGrade_ > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(Form const &obj)
{
	if (this != &obj)
	{
		*(const_cast<std::string*>(&this->name_)) = obj.name_;
		*(const_cast<int*>(&this->signGrade_)) = obj.signGrade_;
		*(const_cast<int*>(&this->execGrade_)) = obj.execGrade_;
		this->signed_ = obj.signed_;
	}
	return (*this);
}

Form::Form(Form const &obj)
	: name_(obj.name_), signGrade_(obj.signGrade_), execGrade_(obj.execGrade_), signed_(obj.signed_)
{
}

Form::~Form()
{
}

std::string	const &Form::getName() const
{
	return (this->name_);
}

int const &Form::getSignGrade() const
{
	return (this->signGrade_);
}

int const &Form::getExecGrade() const
{
	return (this->execGrade_);
}

bool const &Form::getSigned() const
{
	return (this->signed_);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Grade TOO HIGH");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Grade TOO LOW");
}

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
	return (out << "Form " <<obj.getName() << ", sign-grade " << obj.getSignGrade() << ", exec-grade " << obj.getExecGrade() << ", signed " << obj.getSigned());
}

void	Form::beSigned(Bureaucrat const &obj)
{
	if (obj.getGrade() <= this->signGrade_)
		this->signed_ = true;
	else
		throw GradeTooHighException();
}
