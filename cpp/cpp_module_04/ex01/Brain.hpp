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

}

Brain::~Brain()
{
}


#endif