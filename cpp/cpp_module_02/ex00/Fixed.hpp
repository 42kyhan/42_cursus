#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_num;
	static const int	_bits = 8;	
public:
	Fixed(void);
	Fixed(Fixed& n);
	~Fixed(void);
	Fixed& operator=(const Fixed& n);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
