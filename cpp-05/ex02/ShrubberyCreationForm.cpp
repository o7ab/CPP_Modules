#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		this->issigned = other.issigned;
	}
	return *this;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->issigned = true;
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (this->issigned == false)
		throw AForm::GradeTooLowException();
	else
	{
		std::string filename = this->target + "_shrubbery";
		std::ofstream ofs(filename.c_str());
		if (ofs.is_open())
		{
			ofs << "          v" << std::endl;
			ofs << "         >X<" << std::endl;
			ofs << "          A" << std::endl;
			ofs << "         d$b" << std::endl;
			ofs << "        d$$b" << std::endl;
			ofs << "       d$$$b" << std::endl;
			ofs << "      d$$$$$b" << std::endl;
			ofs << "     d$$$$$$$b" << std::endl;
			ofs << "    d$$$$$$$$$b" << std::endl;
			ofs << "   d$$$$$$$$$$$b" << std::endl;
			ofs << "  d$$$$$$$$$$$$$b" << std::endl;
			ofs << " d$$$$$$$$$$$$$$$b" << std::endl;
			ofs << "d$$$$$$$$$$$$$$$$$b" << std::endl;
			ofs << "       d$$P" << std::endl;
			ofs << "      d$$P" << std::endl;
		}
		ofs.close();
	}
}
