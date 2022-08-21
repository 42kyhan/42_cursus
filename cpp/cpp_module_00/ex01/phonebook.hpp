#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"
# include "table.hpp"

class Phonebook
{
private:
	Contact	contacts[8];
public:
	void	AddContact(int index);
	void	SearchContact();
};

#endif