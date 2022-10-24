#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	p1("jaemjeon");
	ScavTrap	p2("kyhan");
	ScavTrap	clone(p1);
	ScavTrap	bot("babo");

	bot = p2;
	p1.attack("kyhan");
	p2.takeDamage(20);
	p2.beRepaired(10);
	p1.attack("jaemjeon");
	p1.takeDamage(20);
	p1.beRepaired(200);
	bot.takeDamage(10);
	clone.attack("ebebebebe");
}
