#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string const   target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		virtual void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#endif

