#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
	private:
		std::string complaint;
	public:
		Harl();
		~Harl();
		void debug();
		void info();
		void warning();
		void error();
		void wrong();
		void Complaint(std::string line);
};

#endif