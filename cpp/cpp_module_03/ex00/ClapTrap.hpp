#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	ClapTrap(void);
public:
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const &obj);
	~ClapTrap(void);
	ClapTrap& operator=(ClapTrap const &obj);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
