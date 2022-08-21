#include "table.hpp"

std::string	Table::CutString(std::string str)
{
	std::string	tmp;

	if (str.size() > 10)
	{
		str[9] = '.';
		tmp = str.substr(0, 10);
		str = tmp;
	}
	return (str);
}

void	Table::PrintAll(Contact contactList[8])
{
	std::cout << std::setw(11) << "Index|";
	std::cout << std::setw(11) << "FirstName|";
	std::cout << std::setw(11) << "LastName|";
	std::cout << std::setw(10) << "Nickname";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << '|';
		std::cout << std::setw(10) << CutString(contactList[i].GetFirstName()) << '|';
		std::cout << std::setw(10) << CutString(contactList[i].GetLastName()) << '|';
		std::cout << std::setw(10) << CutString(contactList[i].GetNickname()) << std::endl;
	}
	std::cout << std::endl;
}

void	Table::PrintContact(Contact contactList[8], int index)
{
	if (index > 0 && index < 9)
	{
		if (contactList[index - 1].GetFirstName().empty())
			std::cout << "This contact is empty" << std::endl;
		else
			contactList[index - 1].GetInfo(index);
	}
	else
		std::cout << "Could not find contact" << std::endl;
}