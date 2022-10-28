#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(Ice const &obj);
	Ice& operator=(Ice const &obj);
	AMateria* clone() const;
	void	use(ICharacter &target);
};

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice& Ice::operator=(Ice const &obj)
{
	if (this != &obj)
	{
		this->type_ = obj.type_;
	}
	return (*this);
}

Ice::Ice(Ice const &obj)
{
	*this = obj;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

#endif