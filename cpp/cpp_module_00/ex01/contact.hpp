#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
public:
	void	Add();
	void	GetInfo(int index);
	std::string	GetFirstName()
	{
		return (this->FirstName);
	}
	std::string	GetLastName()
	{
		return (this->LastName);
	}
	std::string	GetNickname()
	{
		return (this->Nickname);
	}
};

#endif