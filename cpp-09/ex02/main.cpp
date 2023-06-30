#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./a.out \"<numbers>\"" << std::endl;
		return (1);
	}
	std::string str(argv[1]);
	PmergeMe p;
	// p.fillMe(str);
	p.mergeMe(str);

}