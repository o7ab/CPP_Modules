#include "iter.hpp"

void	test(int &i)
{
	std::cout << i << std::endl;
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	iter(array, 5, test);
	return 0;
}