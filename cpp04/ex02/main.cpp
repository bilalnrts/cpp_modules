#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal *animalArray[10];

	int	i = 0;
	while (i < 10)
	{
		if (i < 5)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
		i++;
	}
	std::cout << std::endl;
	Cat cat(*(Cat *)animalArray[0]);
	std::cout <<cat.getBrain().getIdea(3) << std::endl;
	Dog dog(*(Dog *)animalArray[6]);
	std::cout << dog.getBrain().getIdea(1) << std::endl;
	cat.makeSound();
	dog.makeSound();
	animalArray[3]->makeSound();
	animalArray[8]->makeSound();
	i = 0;
	while (i < 10)
	{
		delete animalArray[i];
		i++;
	}
	return 0;
}
