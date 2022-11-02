#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	return ((*dynamic_cast<RobotomyRequestForm*>(&Form::operator=(obj))));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) : Form(obj)
{
	setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(target, 72, 45)
{
	setType("RobotomyRequestForm");
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int tmp = (rand() % 2);
	executable(executor);
	std::cout << "위우이위ㅣ우우이ㅜㅟ우이ㅟㅜ위위위 어쨋든 드릴소리임" << std::endl;
	if (!tmp)
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getName() << " failed to be robotomized" << std::endl;
}
