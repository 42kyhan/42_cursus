#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point& p) : x(p.getX()), y(p.getY())
{
}

Point::~Point()
{
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}

Point& Point::operator=(const Point& p)
{
	if (this != &p)
	{
		const_cast<Fixed&>(x) = p.getX();
		const_cast<Fixed&>(y) = p.getY();
	}
	return (*this);
}
