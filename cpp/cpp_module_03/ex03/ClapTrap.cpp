#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "default";
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
}

ClapTrap::ClapTrap(std::string const name)
 : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name : " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
 : _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage)
{
	std::cout << "ClapTrap Name : " << this->_name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target 
	<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead by " << amount << " Damage" << std::endl;
		this->_energyPoints = 0;
	}
	else
	{
		this->_energyPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount 
		<< " Damage, remaining HP is " << this->_energyPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name 
		<< " is revived, and is repaired by " << amount << " Energy!!!" << std::endl;
	}
	else
	{
		this->_energyPoints += amount;
		std::cout << "ClapTrap " << this->_name << " is repaired by " 
		<< amount << " and remaining HP is " << this->_energyPoints << std::endl;
	}
}

ClapTrap& ClapTrap::operator=(ClapTrap const &obj)
{
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "ClapTrap " << this->_name << " copy assignment is called" << std::endl;
	return (*this);
}
