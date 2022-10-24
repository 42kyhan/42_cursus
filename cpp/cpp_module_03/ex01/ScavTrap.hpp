#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &obj);
	~ScavTrap();
	void	attack(const std::string &target);
	void	guardGate();

	ScavTrap& operator=(ScavTrap const &obj);
};

#endif
