#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span max = Span(10000);
	for (int i = -5000; i < 5000; i++)
	{
		max.addNumber(i);
	}
	std::cout << max.shortestSpan() << std::endl;
	std::cout << max.longestSpan() << std::endl;

	Span zero = Span(0);
	zero.addNumber(1);
	zero.addNumber(1);
	try
	{
		std::cout << zero.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << zero.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
