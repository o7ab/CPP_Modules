#include "ScalarConvertor.hpp"

int main()
{
	ScalarConvertor sc;
	std::string str;
	while (1)
	{
		std::cout << "Enter a string: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		sc.convert(str);
	}
	return 0;
}