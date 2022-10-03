#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies;
	int		i;

	i = 0;
	zombies = zombieHorde(10, "foo");
	while (i < 10)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
}