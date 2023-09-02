#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	Cure		cure;
	Ice			ice;
	Character	c("bilal");
	Character	d("salih");

	c.equip(&cure);
	c.equip(&ice);
	c.use(1, d);
	system("leaks game");
	return (0);
}
