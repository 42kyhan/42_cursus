#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	main_main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound! j->makeSound();
	meta->makeSound();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	delete meta;
	delete j;
	delete i;
	delete k;
}

int main()
{
	main_main();
	system("leaks ex00");
	return 0;
}
