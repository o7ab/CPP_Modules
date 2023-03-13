#include "Base.hpp"

Base::~Base()
{
}

Base * Base::generate(void)
{
	Base *base;
	srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
		case 0:
		{
			A* store = new A;
			base = dynamic_cast<Base *>(store);
			return base;
		}
		case 1:
		{
			B* store = new B;
			base = dynamic_cast<Base *>(store);
			return base;
		}
		case 2:
		{
			C* store = new C;
			base = dynamic_cast<Base *>(store);
			return base;
		}
		default:
			return NULL;
	}
}

void Base::identify(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The pointer is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The pointer is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The pointer is C" << std::endl;
}

void Base::identify(Base & p)
{
	try{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "The reference is A" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "The reference is not A" << std::endl;
	}
	try{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cerr << "The reference is B" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "The reference is not B" << std::endl;
	}
	try{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cerr << "The reference is C" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "The reference is not C" << std::endl;
	}
}