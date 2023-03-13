#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{	
	try{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
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

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::string Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::incrementGrade(){
	try{
		if (this->grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->grade--;
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(){
	try{
		if (this->grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade++;
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm & src){
	try{
		if (this->grade > src.getGradeToSign())
			throw Bureaucrat::GradeTooLowException();
		else
		{
			src.beSigned(*this);
			std::cout << this->name << " signs " << src.getName() << std::endl;
		}
	}
	catch(std::exception & e){
		std::cout << this->name << " cannot sign " << src.getName() << " because their " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try{
		if (this->grade > form.getGradeToExecute())
			throw Bureaucrat::GradeTooLowException();
		else
		{
			form.execute(*this);
			std::cout << this->name << " executes " << form.getName() << std::endl;
		}
	}
	catch(std::exception & e){
		std::cout << this->name << " cannot execute " << form.getName() << " because their " << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src){
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}