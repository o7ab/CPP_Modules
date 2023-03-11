#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	Animal *Animal[6];
	for (int i = 0; i < 6; ++i)
	{
		if (i % 2 == 0)
			Animal[i] = new Cat();
		else
			Animal[i] = new Dog();
		Animal[i]->makeSound();
	}
	for (int i = 0; i < 6; ++i)
	{
		delete Animal[i];
	}
	Dog Dalmatian;
	Dog Perdita = Dalmatian;
	for (int i = 0; i < 50; ++i)
	{
		Dalmatian.getBrain()->setIdea(i, "Fight cruella\n");
		Perdita.getBrain()->setIdea(i, "Eat Cruela\n");
	}
	std::cout << Dalmatian.getBrain()->getIdea(3);
	std::cout << Perdita.getBrain()->getIdea(3);
}