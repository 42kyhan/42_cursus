#ifndef TABLE_HPP
# define TABLE_HPP

# include "contact.hpp"

class Table
{
private:
	std::string	CutString(std::string str);
public:
	void	PrintAll(Contact contactList[8]);
	void	PrintContact(Contact contactList[8], int index);
};

#endif