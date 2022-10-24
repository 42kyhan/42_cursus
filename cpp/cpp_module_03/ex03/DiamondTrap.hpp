#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string const name);
	DiamondTrap(DiamondTrap const &obj);
	DiamondTrap&	operator=(DiamondTrap const &obj);
	~DiamondTrap(void);
	void	whoAmI();
	void	attack(std::string const &target);
	void	print();
};

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(void) : _name(ClapTrap::_name)
{
	ClapTrap::_name = _name + "_clap_name";
	this->_attackDamage = 30;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_attackDamage = 30;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj), _name(obj._name)
{
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &obj)
{
	this->_name = obj._name;
	this->_attackDamage = obj._attackDamage;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	std::cout << "DiamondTrap " << this->_name << " copy assignment called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->_name << ", ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::print()
{
	std::cout << this->_attackDamage << " " << this->_energyPoints << " " << this->_hitPoints << std::endl;
}

#endif
