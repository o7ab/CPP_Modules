#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string line;
	std::cout << "Please enter a complaint: " << std::endl;
	std::getline(std::cin, line);
	harl.Complaint(line);
	return (0);
}