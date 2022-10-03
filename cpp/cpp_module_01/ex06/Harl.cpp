#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

int	Harl::complain(std::string level)
{
	std::string	levelArray[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string	*levelArrayPTR = std::find(levelArray, levelArray + 4, level);
	int	index = levelArrayPTR - levelArray;
	if (levelArrayPTR == levelArray + 4)
		return (0);

	void	(Harl::*ptr)(void);
	int	cnt = 0;
	switch (index)
	{
	case 0:
		ptr = &Harl::debug;
		(this->*ptr)();
		cnt++;
	case 1:
		ptr = &Harl::info;
		(this->*ptr)();
		cnt++;
	case 2:
		ptr = &Harl::warning;
		(this->*ptr)();
		cnt++;
	case 3:
		ptr = &Harl::error;
		(this->*ptr)();
		cnt++;
	}
	return (cnt);
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
