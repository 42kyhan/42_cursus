#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	m_[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const &obj);
	MateriaSource& operator=(MateriaSource const &obj);

	AMateria *getMateria(int idx) const;
	void	learnMateria(AMateria *m);
	AMateria	*createMateria(std::string const &type);
};

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->m_[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const &obj)
{
	if (this != &obj)
	{
		this->~MateriaSource();
		for (int i = 0; i < 4; i++)
		{
			AMateria const *tmp = obj.getMateria(i);
			if (tmp)
				this->m_[i] = tmp->clone();
			else
				this->m_[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	*this = obj;
}

AMateria* MateriaSource::getMateria(int idx) const
{
	return (this->m_[idx]);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m_[i])
			delete this->m_[i];
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->m_[i])
		{
			this->m_[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m_[i] && this->m_[i]->getType() == type)
			return (this->m_[i]->clone());
	}
	return (NULL);
}

#endif