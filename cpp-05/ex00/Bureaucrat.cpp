#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{	
	try{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception & e){
		std::cout << "Grade is out of range" << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name), grade(src.grade){
	*this = src;
}
Bureaucrat::~Bureaucrat(){}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src){
	if (this != &src)
	{
		this->grade = src.grade;
	}
	return *this;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(){
	std::cout << "Grade too high" << std::endl;
}
Bureaucrat::GradeTooLowException::GradeTooLowException(){
	std::cout << "Grade too low" << std::endl;
}

