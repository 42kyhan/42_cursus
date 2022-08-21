#include "phonebook.hpp"

int	main()
{
	std::string	cmd;
	Phonebook	phonebook;
	int			index;

	index = 0;
	while (1)
	{
		std::cout << "enter cmd: ";
		std::getline(std::cin, cmd);
		// std::cin >> cmd;
		// std::cin.ignore(); cin은 버퍼에 개행 남김 그래서 이 함수로 지워줘야함
		if (!cmd.compare("EXIT"))
			return (0);
		else if (!cmd.compare("SEARCH"))
		{
			std::cout << std::endl;
			phonebook.SearchContact();
		}
		else if (!cmd.compare("ADD"))
		{
			std::cout << std::endl;
			std::cout << std::setw(20) << "****Add Contact****" << std::endl;
			phonebook.AddContact(index);
			std::cout << std::setw(17) << "****Added****" << std:: endl;
			index++;
			if (index == 8)
				index = 0;
		}
		else
			std::cout << "command not found" << std::endl;
	}
	
}