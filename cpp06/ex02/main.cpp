#include "Base.hpp"

int main()
{
	Base *randomPtr = generate();
	identify(randomPtr);
	Base &randomRef = *generate();
	identify(randomRef);
}
