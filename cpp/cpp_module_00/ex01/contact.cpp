#include "contact.hpp"

void	Contact::Add()
{
	std::cout << "First Name: ";
	std::getline(std::cin, FirstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, LastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, Nickname);
	std::cout << "Phone Numeber: ";
	std::getline(std::cin, PhoneNumber);
	std::cout << "Your Darkest Secret: ";
	std::getline(std::cin, DarkestSecret);
}

void	Contact::GetInfo(int index)
{
	std::cout << std::endl << std::setw(10) << "Contact: " << index << std::endl;
	std::cout << std::setw(10) << "First Name: " << FirstName << std::endl;
	std::cout << std::setw(10) << "Last Name: " << LastName << std::endl;
	std::cout << std::setw(10) << "Nickname: " << Nickname << std::endl;
	std::cout << std::setw(10) << "Phone Numeber: " << PhoneNumber << std::endl;
	std::cout << std::setw(10) << "Darkest Secret: " << DarkestSecret << std::endl;
}