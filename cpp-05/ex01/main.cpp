#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("alex", 149);
	Bureaucrat b("bob", 2);
	Form c("Cleaning application", 150, 150);
	Form d("Driver's licence", 5, 5);
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;
	std::cout << "----------------" << std::endl;
	a.signForm(c);
	b.signForm(c);
	a.signForm(d);
	b.signForm(d);
	std::cout << "----------------" << std::endl;
	std::cout << "----------------" << std::endl;
	Form e("exit", 1, 0);
	Form f("failure", 151, 68);
	return 0;
}