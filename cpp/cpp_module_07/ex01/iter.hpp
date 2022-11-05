#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(T const &))
{
	for (std::size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
	std::cout << std::endl;
}

template <typename T>
void print(T const &obj)
{
	std::cout << obj << " ";
}

#endif
