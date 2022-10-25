#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain(void);
	Brain(Brain const &obj);
	~Brain(void);
	Brain&	operator=(Brain const &obj);
};

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &obj)
{
	*this = obj;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(Brain const &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = obj._ideas[i];
	}
	std::cout << "Brain copy assignment called" << std::endl;
	return (*this);
}

#endif
