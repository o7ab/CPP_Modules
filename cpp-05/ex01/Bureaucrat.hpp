#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & src);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form & src);
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

#endif