#include <iostream>

class Base
{
public:
	virtual ~Base();
};

Base::~Base()
{
}

class A : public Base
{
};


class B : public Base
{
};


class C : public Base
{
};


Base *generate(void)
{
	srand(time(NULL));
	int random;
	Base *ret;

	random = rand() % 3;
	switch (random)
	{
	case 0:
		ret = new A;
		break;
	case 1:
		ret = new B;
		break;
	case 2:
		ret = new C;
		break;
	}
	return (ret);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "Pointer is A" << std::endl;
	if (b)
		std::cout << "Pointer is B" << std::endl;
	if (c)
		std::cout << "Pointer is C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "reference is A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "reference is B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "reference is C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	Base *base;

	base = generate();
	identify(base);
	identify(*base);

	delete base;
}
