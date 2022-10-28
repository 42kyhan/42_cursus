#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(Cure const &obj);
	Cure& operator=(Cure const &obj);

	AMateria* clone() const;
	void	use(ICharacter &obj);
};

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure& Cure::operator=(Cure const &obj)
{
	if (this != &obj)
	{
		this->type_ = obj.type_;
	}
	return (*this);
}

Cure::Cure(Cure const &obj)
{
	*this = obj;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

#endif