#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	p1("jaemjeon");
	ClapTrap	p2("kyhan");
	ClapTrap	clone(p1);
	ClapTrap	bot("babo");

	bot = p2;
	p1.attack("kyhan");
	p2.takeDamage(0);
	p2.beRepaired(10);
	p1.attack("jaemjeon");
	p1.takeDamage(999999999);
	p1.beRepaired(9999);
	bot.takeDamage(10);
}
