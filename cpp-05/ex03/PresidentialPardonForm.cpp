#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), target(other.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		this->issigned = other.issigned;
	}
	return *this;
}

void	PresidentialPardonForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->issigned = true;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (this->issigned == false)
		throw AForm::GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}