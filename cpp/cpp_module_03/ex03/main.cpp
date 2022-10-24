#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	ky("kyhan");
	DiamondTrap	clone(ky);
	DiamondTrap	babo("ll");

	babo = ky;
	ky.whoAmI();
	ky.print();
	ky.attack("jaemjeon");
	ky.beRepaired(222);
	ky.takeDamage(12);
}
