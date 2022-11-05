#include "iter.hpp"

int main()
{
	std::string str[3] = {"kyhan", "42", "seoul"};
	int arr[9] = {1, 2, 3, 4 ,5 ,6, 7, 8, 9};
	char c[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "string array print" << std::endl;
	iter(str, 3, print);
	std::cout << std::endl;
	std::cout << "int array print" << std::endl;
	iter(arr, 9, print);
	std::cout << std::endl;
	std::cout << "char array print" << std::endl;
	iter(c, 5, print);
	std::cout << std::endl;
}
