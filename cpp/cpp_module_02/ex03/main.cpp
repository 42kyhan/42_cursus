#include "Point.hpp"

int	main(void)
{
	Point	a(5, 5);
	Point	b(2, 9);
	Point	c(0, 5);
	Point	p(3, 7);
	Point	outP(4, 7);

	std::cout << "Point a.x = " << a.getX() << " a.y = " << a.getY() << std::endl;
	std::cout << "Point b.x = " << b.getX() << " b.y = " << b.getY() << std::endl;
	std::cout << "Point c.x = " << c.getX() << " c.y = " << c.getY() << std::endl;
	std::cout << "Point p.x = " << p.getX() << " p.y = " << p.getY() << std::endl;
	std::cout << "Point p2.x = " << outP.getX() << " outP.y = " << outP.getY() << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "p is in the triangle" << std::endl;
	else
		std::cout << "p is out of the triangle" << std::endl;
	if (bsp(a, b, c, outP))
		std::cout << "outP is in the triangle" << std::endl;
	else
		std::cout << "outP is out of the triangle" << std::endl;
	return 0;
}
