#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap &operator=(const FragTrap &fragTrap);
		~FragTrap();
		void highFivesGuys();
};

#endif