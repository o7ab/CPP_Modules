#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("alex", 149);
	Bureaucrat b("bob", 2);
	std::cout << a;
	std::cout << b;
	b.incrementGrade();
	std::cout << b;
	b.incrementGrade();
	std::cout << b;
	a.decrementGrade();
	std::cout << a;
	a.decrementGrade();
	std::cout << a;

	std::cout << "----------------" << std::endl;
	std::cout << "----------------" << std::endl;

	Bureaucrat c("charlie", 0);
	Bureaucrat d("david", 151);
	return 0;
}