#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::deque<int> d;
	std::list<int> l;
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
		v.push_back(i);
		l.push_back(i);
	}

	try
	{
		std::deque<int>::iterator it = easyfind(d, 9);
		std::cout << "Value 9 found at " << std::distance(d.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>::iterator it = easyfind(l, 3);
		std::cout << "Value 3 found at " << std::distance(l.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>::iterator it = easyfind(v, 10);
		std::cout << "Value 1 found at " << std::distance(v.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
