#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
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

	delete bureaucrat;
	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete shrubberyCreationForm;
	return 0;
}