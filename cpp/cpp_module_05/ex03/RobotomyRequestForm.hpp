#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <math.h>

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm();
public:
	void	execute(Bureaucrat const &executor) const;

	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &obj);
	RobotomyRequestForm& operator=(RobotomyRequestForm const &obj);
	RobotomyRequestForm(std::string const &target);

};

#endif
