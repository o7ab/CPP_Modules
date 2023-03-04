# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
int main()
{
	ClapTrap	bb8("BB8");
	ScavTrap	r2d2("R2D2");
	ScavTrap	c3p0("C3PO");
	ScavTrap	bb10(r2d2);

	r2d2.attack("C3PO");
	c3p0.takeDamage(10);
	c3p0.beRepaired(5);
	bb10.guardGate();
	return 0;
}