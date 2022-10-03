#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::complain(std::string level)
{
	std::string	levelArray[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string	*levelArrayPTR = std::find(levelArray, levelArray + 4, level);
	int	index = levelArrayPTR - levelArray;
	if (levelArrayPTR == levelArray + 4)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	
	std::cout << "[" << *levelArrayPTR << "]" << std::endl;
	void	(Harl::*ptr)(void);
	switch (index)
	{
	case 0:
		ptr = &Harl::debug;
		break ;
	case 1:
		ptr = &Harl::info;
		break ;
	case 2:
		ptr = &Harl::warning;
		break ;
	case 3:
		ptr = &Harl::error;
		break ;
	default:
		break;
	}
	(this->*ptr)();
	std::cout << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
