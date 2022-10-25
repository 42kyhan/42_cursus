#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal(void);
	Animal(Animal const &obj);
	virtual ~Animal(void);
	std::string	getType(void) const;
	Animal& operator=(Animal const &obj);
	virtual void	makeSound(void) const;
};

Animal::Animal(void)
{
	this->_type = "default";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &obj)
{
	this->_type = obj._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const &obj)
{
	if (this != &obj)
		this->_type = obj._type;
	std::cout << "Animal copy assignment called" << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal say nothing" << std::endl;
}

#endif
