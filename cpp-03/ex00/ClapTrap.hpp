#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap{
	private:
		std::string name;
		int hp;
		int energy;
		int attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &clapTrap);
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	setAttackDamage(int attackDamage);
		int		getAttackDamage(void);
};

#endif