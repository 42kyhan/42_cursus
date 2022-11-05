#include "Array.hpp"

void main_main()
{
	Array<int> intArr(10);
	std::cout << "intArr: " << intArr.size() << std::endl;
	for (std::size_t i = 0; i < intArr.size(); i++)
	{
		intArr[i] = i;
	}
	std::cout << "intArr[6]: " << intArr[6] << std::endl;

	Array<std::string> str(3);
	str[0] = "kyhan";
	str[1] = "42";
	str[2] = "seoul";
	for (std::size_t i = 0; i < str.size(); i++)
	{
		std::cout << str[i] << " ";
	}
	std::cout << std::endl;

	Array<std::string> const str2(str);
	for (std::size_t i = 0; i < str2.size(); i++)
	{
		std::cout << str2[i] << " ";
	}
	std::cout << std::endl;

	Array<std::string> str3(9);
	str3 = str;
	for (std::size_t i = 0; i < str3.size(); i++)
	{
		std::cout << str3[i] << " ";
	}
	std::cout << std::endl;

	try
	{
		str[3] = "kkkk";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << str[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	main_main();
	system("leaks ex02");
}
