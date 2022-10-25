#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	std::string	_name;
	Brain*	_brain;
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
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const name)
{
	this->_name = name;
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat " << this->_name << " constructor called" << std::endl;
}

Cat::Cat(Cat const &obj)
{
	*this = obj;
	std::cout << "Cat " << this->_name << " copy constructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_type = obj._type;
		this->_brain = new Brain(*obj._brain);
	}
	std::cout << "Cat " << this->_name << " copy assignment called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat " << this->_name << " 먀야야아아아아ㅏ아아아아아아아ㅏㅏ아아아아ㅏㅏ아아아아ㅏㅏ아아아아아아아아앙 먀야야아아아아아아아앙ㅇ" << std::endl;
}

#endif
