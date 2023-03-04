# include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1;
	ClapTrap clapTrap2("ClapTrap2");
	ClapTrap clapTrap3(clapTrap2);
	clapTrap1 = clapTrap2;
	clapTrap1.attack("clapTrap2");
	clapTrap1.attack("clapTrap2");
	clapTrap1.attack("clapTrap2");
	clapTrap1.attack("clapTrap2");
	clapTrap1.beRepaired(10);
	return 0;
}