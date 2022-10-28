#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	name_;
	AMateria*	inven_[4];
public:
	Character();
	~Character();
	Character(Character const &obj);
	Character& operator=(Character const &obj);
	Character(std::string const name);

	std::string const &getName() const;
	AMateria const *getMateria(int idx) const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter &target);
};

Character::Character() : name_("")
{
}

Character& Character::operator=(Character const &obj)
{
	if (this != &obj)
	{
		this->~Character();

		this->name_ = obj.name_;
		for (int i = 0; i < 4; i++)
		{
			AMateria const *tmp = obj.getMateria(i);
			if (tmp)
				this->inven_[i] = tmp->clone();
			else
				this->inven_[i] = NULL;
		}
	}
	return (*this);
}

Character::Character(std::string const name)
{
	this->name_ = name;
	for (int i = 0; i < 4; i++)
	{
		this->inven_[i] = NULL;
	}
}

Character::Character(Character const &obj)
{
	*this = obj;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inven_[i])
			delete this->inven_[i];
	}
}

std::string const &Character::getName() const
{
	return (this->name_);
}

AMateria const *Character::getMateria(int idx) const
{
	return (this->inven_[idx]);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inven_[i])
		{
			this->inven_[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >3)
		return ;
	this->inven_[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->inven_[idx])
		this->inven_[idx]->use(target);
}

#endif