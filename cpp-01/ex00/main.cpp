#include "Zombie.hpp"

int main()
{
	Zombie* nZombie = newZombie("Ali");
	nZombie->announce();
	delete nZombie;
	randomChump("Chump");
	return 0;
}