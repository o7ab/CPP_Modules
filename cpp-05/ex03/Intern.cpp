#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	int i = 0;
	try{
		(!name.compare("presidential pardon")) ? i = 1 : 0;
		(!name.compare("robotomy request")) ? i = 2 : 0;
		(!name.compare("shrubbery creation")) ? i = 3 : 0;
		switch (i)
		{
			case 1:
				return new PresidentialPardonForm(target);
			case 2:
				return new RobotomyRequestForm(target);
			case 3:
				return new ShrubberyCreationForm(target);
			default:
				throw Intern::UnknownFormException();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return NULL;
}

const char *Intern::UnknownFormException::what() const throw()
{
	return "Unknown form";
}