#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const & src);
		WrongCat &operator=(WrongCat const & copy);
		~WrongCat();
		void makeSound() const;
};

#endif