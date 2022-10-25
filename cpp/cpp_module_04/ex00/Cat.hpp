#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
private:
	std::string	_name;
public:
	Cat(void);
	Cat(std::string const name);
	Cat(Cat const &obj);
	~Cat(void);
	Cat&	operator=(Cat const &obj);
	void	makeSound(void) const;
};

Cat::Cat(void)
{
	this->_name = "default";
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const name)
{
	this->_name = name;
	this->_type = "Cat";
	std::cout << "Cat " << this->_name << " constructor called" << std::endl;
}

Cat::Cat(Cat const &obj)
{
	this->_name = obj._name;
	this->_type = obj._type;
	std::cout << "Cat " << this->_name << " copy constructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_type = obj._type;
	}
	std::cout << "Cat " << this->_name << " copy assignment called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat " << this->_name << " 먀야야아아아아ㅏ아아아아아아아ㅏㅏ아아아아ㅏㅏ아아아아ㅏㅏ아아아아아아아아앙 먀야야아아아아아아아앙ㅇ" << std::endl;
}

#endif
