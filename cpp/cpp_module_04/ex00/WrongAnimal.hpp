#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &obj);
	virtual ~WrongAnimal(void);
	std::string	getType(void) const;
	WrongAnimal& operator=(WrongAnimal const &obj);
	void	makeSound(void) const;
};

WrongAnimal::WrongAnimal(void)
{
	this->_type = "default";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
	this->_type = obj._type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal say nothing" << std::endl;
}

#endif
