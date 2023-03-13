#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		this->issigned = other.issigned;
	}
	return *this;
}

void	RobotomyRequestForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->issigned = true;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand(time(NULL));
	try{
		if (executor.getGrade() > this->gradeToExecute)
			throw AForm::GradeTooLowException();
		else if (this->issigned == false)
			throw AForm::GradeTooLowException();
		else
		{
			std::cout << "Brrrrrrrrrrrrr" << std::endl;
			if (rand() % 2)
				std::cout << this->target << " has been robotomized successfully." << std::endl;
			else
				std::cout << this->target << " robotomization failed." << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}