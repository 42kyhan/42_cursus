#include "phonebook.hpp"

void	Phonebook::AddContact(int index)
{
	contacts[index].Add();
}

void	Phonebook::SearchContact()
{
	int			selected;
	Table		table;
	std::string	str;

	table.PrintAll(contacts);
	std::cout << "Select contact in this list: ";
	std::getline(std::cin, str);
	std::stringstream(str) >> selected;
	table.PrintContact(contacts, selected);
}
