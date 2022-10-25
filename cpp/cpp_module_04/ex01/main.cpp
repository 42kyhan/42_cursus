#include "Cat.hpp"
#include "Dog.hpp"

void	main_main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	const Animal* animal[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
	{
		delete animal[i];
	}
}

int main()
{
	main_main();
	system("leaks ex01");
	return 0;
}
