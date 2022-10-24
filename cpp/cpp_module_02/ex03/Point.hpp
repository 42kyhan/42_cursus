#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const	y;
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point& p);
	Fixed getX(void) const;
	Fixed getY(void) const;
	Point& operator=(const Point &p);
	~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
