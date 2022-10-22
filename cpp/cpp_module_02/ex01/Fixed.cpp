#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_num = 0;
}

Fixed::Fixed(const Fixed& n)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = n;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_num = n << this->_bits;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_num = roundf(n * (1 << this->_bits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_num / (1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_num >> this->_bits);
}

Fixed& Fixed::operator=(const Fixed& n)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &n)
		this->_num = n.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_num);
}

void	Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}
