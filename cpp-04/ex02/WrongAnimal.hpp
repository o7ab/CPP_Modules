#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP



# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal &operator=(WrongAnimal const & copy);
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
};

#endif