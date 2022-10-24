#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_name = "default";
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name)
{
	this->_name = name;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj)
{
	this->_name = obj._name;
	this->_attackDamage = obj._attackDamage;
	this->_energyPoints = obj._energyPoints;
	this->_hitPoints = obj._hitPoints;
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &obj)
{
	this->_name = obj._name;
	this->_attackDamage = obj._attackDamage;
	this->_energyPoints = obj._energyPoints;
	this->_hitPoints = obj._hitPoints;
	std::cout << "FragTrap " << this->_name << " copy assignment called" <<std::endl;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	if (!this->_energyPoints)
	{
		std::cout << "FragTrap " << this->_name << " cannot high five" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " HIGH FIVE ~ !" << std::endl;
	}
}
