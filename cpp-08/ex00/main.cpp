#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	std::vector<int>::iterator it = easyfind(v, 50);
	std::cout << "the chosen iterator is: " << *it << std::endl;
	it = easyfind(v, 13);
	return 0;
}