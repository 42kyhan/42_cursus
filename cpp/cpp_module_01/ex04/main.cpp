#include <fstream>
#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 4 || std::strlen(av[2]) == 0)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	
	std::string	outFile = av[1];
	outFile.append(".replace");

	std::ifstream	ifs;
	std::ofstream	ofs;
	
	ifs.open(av[1]);
	if (ifs.fail())
	{
		std::cout << "Fail to open file" << std::endl;
		return (1);
	}

	ofs.open(outFile);
	if (ofs.fail())
	{
		std::cout << "Fail to create file" << std::endl;
		ifs.close();
		return (1);
	}

	std::string	sub;
	while (true)
	{
		std::getline(ifs, sub);
		size_t	index = sub.find(av[2]);
		if (index == std::string::npos)
		{
			ofs << sub;
			break ;
		}
		ofs << sub.substr(0, index) << av[3];
		sub = sub.substr(index + std::strlen(av[2]));
	}
	
}