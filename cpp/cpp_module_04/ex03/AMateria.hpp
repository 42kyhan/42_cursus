#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type_;
public:
	AMateria(std::string const & type);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	AMateria(void);
	AMateria(AMateria const &obj);
	virtual ~AMateria(void);
	AMateria& operator=(AMateria const &obj);
};

AMateria::AMateria()
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const &type)
{
	this->type_ = type;
}

AMateria::AMateria(AMateria const &obj)
{
	*this = obj;
}

AMateria& AMateria::operator=(AMateria const &obj)
{
	if (this != &obj)
	{
		this->type_ = obj.type_;
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type_);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "use function called on AMateria to " << target.getName() << std::endl;
}

#endif