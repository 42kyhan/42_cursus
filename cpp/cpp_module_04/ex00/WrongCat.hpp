#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	std::string	_name;
public:
	WrongCat(void);
	WrongCat(std::string const name);
	WrongCat(WrongCat const &obj);
	~WrongCat(void);
	WrongCat&	operator=(WrongCat const &obj);
	void	makeSound(void) const;
};

WrongCat::WrongCat(void)
{
	this->_name = "default";
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string const name)
{
	this->_name = name;
	this->_type = "WrongCat";
	std::cout << "WrongCat " << this->_name << " constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &obj)
{
	this->_name = obj._name;
	this->_type = obj._type;
	std::cout << "WrongCat " << this->_name << " copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_type = obj._type;
	}
	std::cout << "WrongCat " << this->_name << " copy assignment called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat " << this->_name << " 먀야야아아아아ㅏ아아아아아아아ㅏㅏ아아아아ㅏㅏ아아아아ㅏㅏ아아아아아아아아앙 먀야야아아아아아아아앙ㅇ" << std::endl;
}

#endif
