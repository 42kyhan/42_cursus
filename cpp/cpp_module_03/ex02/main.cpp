#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	p1("jaemjeon");
	FragTrap	p2("kyhan");
	FragTrap	clone(p1);
	FragTrap	bot("babo");

	bot = p2;
	p1.attack("kyhan");
	p2.takeDamage(20);
	p2.beRepaired(10);
	p1.attack("jaemjeon");
	p1.takeDamage(2000);
	bot.takeDamage(10);
	clone.attack("ebebebebe");
	p1.highFiveGuys();
	p2.highFiveGuys();
}
