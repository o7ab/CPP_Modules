#include "AForm.hpp"

AForm::AForm() : name("default"), issigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string const &name, int const gradeToSign, int const gradeToExecute) : name(name), issigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	try{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

AForm::AForm(AForm const &other) : name(other.name), issigned(other.issigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		this->issigned = other.issigned;
	}
	return *this;
}

std::string const	&AForm::getName() const
{
	return this->name;
}

bool	AForm::getissigned() const
{
	return this->issigned;
}

int		AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int		AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}