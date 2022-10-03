#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie1 = newZombie("foo");
	Zombie *zombie2 = newZombie("boo");

	randomChump("random");

	zombie1->announce();
	zombie2->announce();

	delete zombie1;
	delete zombie2;
}