#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_num = 0;
}

Fixed::Fixed(const Fixed& n)
{
	*this = n;
}

Fixed::Fixed(int const n)
{
	this->_num = n << this->_bits;
}

Fixed::Fixed(float const n)
{
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
}

int	Fixed::getRawBits(void) const
{
	return (this->_num);
}

void	Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed	ret(this->toFloat() + fixed.toFloat());
	return(ret);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed	ret(this->toFloat() - fixed.toFloat());
	return(ret);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed	ret(this->toFloat() * fixed.toFloat());
	return(ret);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed	ret(this->toFloat() / fixed.toFloat());
	return(ret);
}

Fixed&	Fixed::operator++(void)
{
	this->_num++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	ret(*this);

	this->_num++;
	return (ret);
}

Fixed&	Fixed::operator--(void)
{
	this->_num--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	ret(*this);

	this->_num--;
	return (ret);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
