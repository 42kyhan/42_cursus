#include "Point.hpp"

Point	operator-(Point const &a, Point const &b)
{
	return (Point((a.getX() - b.getX()).toFloat(), (a.getY() - b.getY()).toFloat()));
}

Fixed	operator*(Point const &a, Point const &b)
{
	return (Fixed(a.getX() * b.getY() - a.getY() * b.getX()));
}

bool	operator~(const Fixed &cw)
{
	return (cw > Fixed(0));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if ((a.getX() == b.getX() && a.getY() == b.getY())
		|| (a.getX() == c.getX() && a.getY() == c.getY())
		|| (c.getX() == b.getX() && c.getY() == b.getY()))
		return (false);
	
	Point	ab = a - b;
	Point	ap = a - point;
	Point	bc = b - c;
	Point	bp = b - point;
	Point	ca = c - a;
	Point	cp = c - point;

	if ((~(ab * bp) && ~(bc * cp) && ~(ca * ap)) 
		|| (!(~(ab * bp)) && !(~(bc * cp)) && !(~(ca * ap))))
		return (true);
	return (false);
}
