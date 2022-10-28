#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	std::string	_name;
	Brain*	_brain;
public:
	Dog(void);
	Dog(Dog const &obj);
	Dog(std::string const name);
	~Dog(void);
	Dog&	operator=(Dog const &obj);

	void	makeSound(void) const;
};

Dog::Dog(void)
{
	this->_name = "default";
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const name)
{
	this->_name = name;
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog " << this->_name << " constructor called" << std::endl;
}

Dog::Dog(Dog const &obj)
{
	*this = obj;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_type = obj._type;
		this->_brain = new Brain(*obj._brain);
	}
	std::cout << "Dog " << this->_name << " copy assignment called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog " << this->_name << " : 멍멍멍멍멈엄엄엄엄ㅇㅇㅇ멈멈엄엄엄엄왈왈왈와ㅏㄹ와ㅏㅇ와와와와와ㅘㅘㅘㅘㄹㄹㄹ왈왈ㅇ뢍롸" << std::endl;
}

#endif
