#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*zombie;

	zombie = new Zombie[N];
	i = 0;
	while(i < N)
	{
		zombie[i].setName(name + std::to_string(i));
		i++;
	}
	return (zombie);
}