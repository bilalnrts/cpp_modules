#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	{
	Cure		cure;
	Ice			ice;
	Ice			ice1;
	Ice			ice2;
	Character	c("bilal");
	Character	d("salih");
	Cure	*a = new Cure();

	c.equip(a);
	c.equip(&ice);
	c.equip(&ice1);
	c.equip(&ice2);
	c.unequip(1);
	c.use(0, d);
	}
	return (0);
}
