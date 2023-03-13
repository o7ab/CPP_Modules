#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string const   name;
		bool                issigned;
		int const           gradeToSign;
		int const           gradeToExecute;

	public:
		AForm();
		AForm(std::string const &name, int const gradeToSign, int const gradeToExecute);
		AForm(AForm const &other);
		virtual ~AForm();
		AForm &operator=(AForm const &other);
		std::string const	&getName() const;
		bool	getissigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;
		virtual void beSigned(Bureaucrat const &bureaucrat) = 0;
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

# endif