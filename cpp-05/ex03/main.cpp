#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern *intern = new Intern();
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
	PresidentialPardonForm *presidentialPardonForm = new PresidentialPardonForm("PresidentialPardonForm");
	RobotomyRequestForm *robotomyRequestForm = new RobotomyRequestForm("RobotomyRequestForm");
	ShrubberyCreationForm *shrubberyCreationForm = new ShrubberyCreationForm("ShrubberyCreationForm");

	bureaucrat->signForm(*presidentialPardonForm);
	bureaucrat->signForm(*robotomyRequestForm);
	bureaucrat->signForm(*shrubberyCreationForm);
	bureaucrat->executeForm(*presidentialPardonForm);
	bureaucrat->executeForm(*robotomyRequestForm);
	bureaucrat->executeForm(*shrubberyCreationForm);

	std::cout << "----------------" << std::endl;
	std::cout << "----------------" << std::endl;
	AForm* presform= intern->makeForm("presidential pardon", "PresidentialPardonForm");
	AForm* robotform= intern->makeForm("robotomy request", "RobotomyRequestForm");
	AForm* shrubform= intern->makeForm("shrubbery creation", "ShrubberyCreationForm");
	std::cout << "----------------" << std::endl;
	std::cout << "----------------" << std::endl;
	bureaucrat->signForm(*presform);
	bureaucrat->signForm(*robotform);
	bureaucrat->signForm(*shrubform);
	bureaucrat->executeForm(*presform);
	bureaucrat->executeForm(*robotform);
	bureaucrat->executeForm(*shrubform);
	delete bureaucrat;
	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete shrubberyCreationForm;
	delete intern;
	return 0;
}