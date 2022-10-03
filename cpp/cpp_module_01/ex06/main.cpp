#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	if (!harl.complain(argv[1]))
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}