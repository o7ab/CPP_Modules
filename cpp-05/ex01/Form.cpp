#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	try{
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw Form::GradeTooHighException();
		else if (gradeToSign > 150 || gradeToExecute > 150)
			throw Form::GradeTooLowException();
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

Form::Form(Form const & src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute){
	*this = src;
}

Form::~Form(){}

Form & Form::operator=(Form const & src){
	if (this != &src)
	{
		this->isSigned = src.isSigned;
	}
	return *this;
}

std::string Form::getName() const{
	return this->name;
}

bool Form::getIsSigned() const{
	return this->isSigned;
}

int Form::getGradeToSign() const{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const{
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat & src){
	try{
		if (src.getGrade() > this->gradeToSign)
			throw Form::GradeTooLowException();
		else
			this->isSigned = true;
	}
	catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::ostream & operator<<(std::ostream & o, Form const & src){
	o << "Form " << src.getName() << " is signed: " << src.getIsSigned() << ", grade to sign: " << src.getGradeToSign() << ", grade to execute: " << src.getGradeToExecute() << std::endl;
	return o;
}