# ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		ScavTrap & operator=(ScavTrap const & rhs);
		void	guardGate(void);
};

#endif