#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>
#include <exception>

class Span
{
	private:
		std::vector<int>	array;
	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span();
		Span	&operator=(Span const &rhs);
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	AddRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		class	FullArrayException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif