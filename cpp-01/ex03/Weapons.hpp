#ifndef WEAPONS_HPP
#define WEAPONS_HPP

#include <iostream>

class Weapons{
	private:
		std::string type;
	public:
		Weapons();
		Weapons(std::string type);
		~Weapons();
		std::string getType();
		void setType(std::string type);
};

#endif