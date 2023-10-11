#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	int	random;

	srand(time(0));
	random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type : A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type : B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type : C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "Type : A" << std::endl;
		(void)a;
	} catch(const std::bad_cast &) {}
	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "Type : B" << std::endl;
		(void)b;
	} catch(const std::bad_cast &) {}
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "Type : C" << std::endl;
		(void)c;
	} catch(const std::bad_cast &) {}
}
