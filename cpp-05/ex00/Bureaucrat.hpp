#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & src);
		// std::string getName() const;
		// int getGrade() const;
		// void incrementGrade();
		// void decrementGrade();
		class GradeTooHighException : public std::exception{
			// public:
			// 	virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			// public:
			// 	virtual const char* what() const throw();
		};
};

#endif