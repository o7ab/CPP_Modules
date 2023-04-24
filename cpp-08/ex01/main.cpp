#include "Span.hpp"

int main()
{
	srand(time(NULL));
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::vector<int> v;
	for(int i = 0; i < 10000; i++)
		v.push_back(rand() % 100);
	sp.AddRange(v.begin(), v.end());
	std::vector<int>::iterator it = sp.getbegin();
	for(int i = 0; i < 10000; i++)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}