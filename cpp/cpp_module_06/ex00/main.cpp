#include "Convert.hpp"

void	convert(char *av)
{
	Convert ccc(av);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "똑바로 입력바람" << std::endl;
		return (1);
	}
	else
		convert(av[1]);
	return (0);
}
