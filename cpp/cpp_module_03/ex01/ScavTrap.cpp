#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Name : " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string const name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Name : " << this->_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj)
{
	this->_name = obj._name;
	this->_attackDamage = obj._attackDamage;
	this->_energyPoints = obj._energyPoints;
	this->_hitPoints = obj._hitPoints;
	std::cout << "ScavTrap Name : " << this->_name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &obj)
{
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_attackDamage = obj._attackDamage;
	this->_energyPoints = obj._energyPoints;
	std::cout << "ScavTrap " << this->_name << " copy assignment is called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << this->_name << " attacks " << target 
	<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_energyPoints)
		std::cout << "ScavTrap " << this->_name << " has entered gate guard mode." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot enter gate guard mode . . . he's dead" << std::endl;
}
