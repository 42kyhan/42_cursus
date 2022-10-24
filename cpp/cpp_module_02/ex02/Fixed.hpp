#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
private:
	int	_num;
	static const int	_bits = 8;	
public:
	Fixed(void);
	Fixed(const Fixed& n);
	Fixed(int const n);
	Fixed(float const n);
	~Fixed(void);
	Fixed& operator=(const Fixed& n);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;

	bool	operator<(Fixed const &fixed) const;
	bool	operator>(Fixed const &fixed) const;
	bool	operator<=(Fixed const &fixed) const;
	bool	operator>=(Fixed const &fixed) const;
	bool	operator==(Fixed const &fixed) const;
	bool	operator!=(Fixed const &fixed) const;

	Fixed	operator+(Fixed const &fixed) const;
	Fixed	operator-(Fixed const &fixed) const;
	Fixed	operator*(Fixed const &fixed) const;
	Fixed	operator/(Fixed const &fixed) const;

	Fixed&	operator++(void);
	const Fixed	operator++(int);
	Fixed&	operator--(void);
	const Fixed	operator--(int);

	static Fixed&	min(Fixed &a, Fixed &b);
	static const Fixed&	min(Fixed const &a, Fixed const &b);
	static Fixed&	max(Fixed &a, Fixed &b);
	static const Fixed&	max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);

#endif
